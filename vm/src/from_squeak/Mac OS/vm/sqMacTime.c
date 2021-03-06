/****************************************************************************
*   PROJECT: Mac time and millisecond clock logic 
*   FILE:    sqMacTime.c
*   CONTENT: 
*
*   AUTHOR:  John McIntosh.
*   ADDRESS: 
*   EMAIL:   johnmci@smalltalkconsulting.com
*   RCSID:   $Id: sqMacTime.c 1468 2006-04-19 02:39:08Z johnmci $
*
*   NOTES: 
*  Feb 22nd, 2002, JMM moved code into 10 other files, see sqMacMain.c for comments
*  Feb 27th, 2002, JMM a bit of cleanup for carbon event usage
*  Apr 17th, 2002, JMM Use accessors for VM variables.
*  Apr 25th, 2002, JMM low res clock is broken after 0x7FFFFFF
*  3.9.1b2 Oct 4th, 2005 Jmm add MillisecondClockMask
 3.8.11b1 Mar 4th, 2006 JMM refactor, cleanup and add headless support

*****************************************************************************/
#include "sq.h"
#include "sqMacTime.h"
#include "sqMacUIEvents.h"

#include <pthread.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include "sqaio.h"

static struct timeval	 startUpTime;
/*
 * In the Cog VMs time management is in platforms/unix/vm/sqUnixHeartbeat.c.
 */
#if STACKVM
/*
 * Compute the time via the old method for sanity checking purposes.
 */
int ioOldMSecs() {
  struct timeval now;
  gettimeofday(&now, 0);
  if ((now.tv_usec-= startUpTime.tv_usec) < 0) {
    now.tv_usec+= 1000000;
    now.tv_sec-= 1;
  }
  now.tv_sec-= startUpTime.tv_sec;
  return (now.tv_usec / 1000 + now.tv_sec * 1000);
}
void SetUpTimers(void)
{
extern void ioInitTime(void);

  /* set up the backwardcompatibility micro/millisecond clock */
    gettimeofday(&startUpTime, 0);
  /* setup the spiffy new 64-bit microsecond clock. */
	ioInitTime();
}
#else /* STACKVM */

void SetUpTimers(void)
{
  /* set up the micro/millisecond clock */
    gettimeofday(&startUpTime, 0);
}

int ioMicroMSecs(void)
{
  struct timeval now;
  gettimeofday(&now, 0);
  if ((now.tv_usec-= startUpTime.tv_usec) < 0) {
    now.tv_usec+= 1000000;
    now.tv_sec-= 1;
  }
  now.tv_sec-= startUpTime.tv_sec;
  return (now.tv_usec / 1000 + now.tv_sec * 1000);
}

int ioSeconds(void) {
    time_t unixTime;

    unixTime = time(0);
    unixTime += localtime(&unixTime)->tm_gmtoff;
    /* Squeak epoch is Jan 1, 1901.  Unix epoch is Jan 1, 1970: 17 leap years
        and 52 non-leap years later than Squeak. */
    return unixTime + ((52*365UL + 17*366UL) * 24*60*60UL);
}

int ioRelinquishProcessorForMicroseconds(int microSeconds) {
	/* This operation is platform dependent. 	 */

    long	   realTimeToWait,now;
	extern int getNextWakeupTick();

    now = (ioMSecs() & MillisecondClockMask);
    if (getNextWakeupTick() <= now)
        if (getNextWakeupTick() == 0)
            realTimeToWait = microSeconds;
        else {
            return 0;
    }
    else
        realTimeToWait = (getNextWakeupTick() - now) * 1000; 

	aioSleepForUsecs(realTimeToWait);

	return 0;
}


#undef ioMSecs
//Issue with unix aio.c sept 2003

int ioMSecs() {
    return ioMicroMSecs();
}
#endif /* STACKVM */

time_t convertToSqueakTime(time_t unixTime)
{
#ifdef HAVE_TM_GMTOFF
  unixTime+= localtime(&unixTime)->tm_gmtoff;
#else
# ifdef HAVE_TIMEZONE
  unixTime+= ((daylight) * 60*60) - timezone;
# else
#  error: cannot determine timezone correction
# endif
#endif
  /* Squeak epoch is Jan 1, 1901.  Unix epoch is Jan 1, 1970: 17 leap years
     and 52 non-leap years later than Squeak. */
  return unixTime + ((52*365UL + 17*366UL) * 24*60*60UL);
}
