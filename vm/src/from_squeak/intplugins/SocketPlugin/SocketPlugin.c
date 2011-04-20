/* Automatically generated from Squeak on 23 January 2011 3:55:47 pm 
   by VMMaker 4.4.7
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif
#include "SocketPlugin.h"

#include "sqMemoryAccess.h"


/*** Constants ***/

/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
#pragma export on
EXPORT(const char*) getModuleName(void);
#pragma export off
static sqInt halt(void);
#pragma export on
EXPORT(sqInt) initialiseModule(void);
#pragma export off
static sqInt intToNetAddress(sqInt addr);
#pragma export on
EXPORT(sqInt) moduleUnloaded(char *aModuleName);
#pragma export off
static sqInt msg(char *s);
static sqInt netAddressToInt(unsigned char *  ptrToByteArray);
#pragma export on
EXPORT(sqInt) primitiveDisableSocketAccess(void);
EXPORT(sqInt) primitiveHasSocketAccess(void);
EXPORT(sqInt) primitiveInitializeNetwork(void);
EXPORT(sqInt) primitiveResolverAbortLookup(void);
EXPORT(sqInt) primitiveResolverAddressLookupResult(void);
EXPORT(sqInt) primitiveResolverError(void);
EXPORT(sqInt) primitiveResolverGetAddressInfoFamily(void);
EXPORT(sqInt) primitiveResolverGetAddressInfo(void);
EXPORT(sqInt) primitiveResolverGetAddressInfoNext(void);
EXPORT(sqInt) primitiveResolverGetAddressInfoProtocol(void);
EXPORT(sqInt) primitiveResolverGetAddressInfoResult(void);
EXPORT(sqInt) primitiveResolverGetAddressInfoSize(void);
EXPORT(sqInt) primitiveResolverGetAddressInfoType(void);
EXPORT(sqInt) primitiveResolverGetNameInfo(void);
EXPORT(sqInt) primitiveResolverGetNameInfoHostResult(void);
EXPORT(sqInt) primitiveResolverGetNameInfoHostSize(void);
EXPORT(sqInt) primitiveResolverGetNameInfoServiceResult(void);
EXPORT(sqInt) primitiveResolverGetNameInfoServiceSize(void);
EXPORT(sqInt) primitiveResolverHostNameResult(void);
EXPORT(sqInt) primitiveResolverHostNameSize(void);
EXPORT(sqInt) primitiveResolverLocalAddress(void);
EXPORT(sqInt) primitiveResolverNameLookupResult(void);
EXPORT(sqInt) primitiveResolverStartAddressLookup(void);
EXPORT(sqInt) primitiveResolverStartNameLookup(void);
EXPORT(sqInt) primitiveResolverStatus(void);
EXPORT(sqInt) primitiveSocketBindTo(void);
EXPORT(sqInt) primitiveSocketBindToPort(void);
EXPORT(sqInt) primitiveSocketConnectTo(void);
EXPORT(sqInt) primitiveSocketConnectToPort(void);
EXPORT(sqInt) primitiveSocketGetOptions(void);
EXPORT(sqInt) primitiveSocketListenOnPort(void);
EXPORT(sqInt) primitiveSocketListenOnPortBacklog(void);
EXPORT(sqInt) primitiveSocketListenOnPortBacklogInterface(void);
EXPORT(sqInt) primitiveSocketListenWithBacklog(void);
EXPORT(sqInt) primitiveSocketLocalAddressResult(void);
EXPORT(sqInt) primitiveSocketReceiveDataBufCount(void);
EXPORT(sqInt) primitiveSocketReceiveUDPDataBufCount(void);
EXPORT(sqInt) primitiveSocketRemoteAddressResult(void);
EXPORT(sqInt) primitiveSocketSendDataBufCount(void);
EXPORT(sqInt) primitiveSocketSendUDPDataBufCount(void);
EXPORT(sqInt) primitiveSocketSetOptions(void);
EXPORT(sqInt) primitiveSocketAbortConnection(void);
EXPORT(sqInt) primitiveSocketAccept(void);
EXPORT(sqInt) primitiveSocketAccept3Semaphores(void);
EXPORT(sqInt) primitiveSocketAddressGetPort(void);
EXPORT(sqInt) primitiveSocketAddressSetPort(void);
EXPORT(sqInt) primitiveSocketCloseConnection(void);
EXPORT(sqInt) primitiveSocketConnectionStatus(void);
EXPORT(sqInt) primitiveSocketCreate(void);
EXPORT(sqInt) primitiveSocketCreate3Semaphores(void);
EXPORT(sqInt) primitiveSocketDestroy(void);
EXPORT(sqInt) primitiveSocketError(void);
EXPORT(sqInt) primitiveSocketListenWithOrWithoutBacklog(void);
EXPORT(sqInt) primitiveSocketLocalAddress(void);
EXPORT(sqInt) primitiveSocketLocalAddressSize(void);
EXPORT(sqInt) primitiveSocketLocalPort(void);
EXPORT(sqInt) primitiveSocketReceiveDataAvailable(void);
EXPORT(sqInt) primitiveSocketRemoteAddress(void);
EXPORT(sqInt) primitiveSocketRemoteAddressSize(void);
EXPORT(sqInt) primitiveSocketRemotePort(void);
EXPORT(sqInt) primitiveSocketSendDone(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
#pragma export off
static sqInt socketRecordSize(void);
static SQSocket * socketValueOf(sqInt socketOop);
static sqInt sqAssert(sqInt aBool);
/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SocketPlugin 23 January 2011 (i)"
#else
	"SocketPlugin 23 January 2011 (e)"
#endif
;
static void * sCCLOPfn;
static void * sCCSOTfn;
static void * sCCTPfn;
static void * sDSAfn;
static void * sHSAfn;



/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine * getInterpreter(void) {
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*) getModuleName(void) {
	return moduleName;
}

static sqInt halt(void) {
	;
}

EXPORT(sqInt) initialiseModule(void) {
	sDSAfn = interpreterProxy->ioLoadFunctionFrom("secDisableSocketAccess", "SecurityPlugin");
	sHSAfn = interpreterProxy->ioLoadFunctionFrom("secHasSocketAccess", "SecurityPlugin");
	sCCTPfn = interpreterProxy->ioLoadFunctionFrom("secCanConnectToPort", "SecurityPlugin");
	sCCLOPfn = interpreterProxy->ioLoadFunctionFrom("secCanListenOnPort", "SecurityPlugin");
	sCCSOTfn = interpreterProxy->ioLoadFunctionFrom("secCanCreateSocketOfType", "SecurityPlugin");
	return socketInit();
}


/*	Convert the given 32-bit integer into an internet network address represented as a four-byte ByteArray. */

static sqInt intToNetAddress(sqInt addr) {
	char *  naPtr;
	sqInt netAddressOop;

	netAddressOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), 4);
	naPtr = (char *) interpreterProxy->firstIndexableField(netAddressOop);
	naPtr[0] = (((char) ((((usqInt) addr) >> 24) & 255)));
	naPtr[1] = (((char) ((((usqInt) addr) >> 16) & 255)));
	naPtr[2] = (((char) ((((usqInt) addr) >> 8) & 255)));
	naPtr[3] = (((char) (addr & 255)));
	return netAddressOop;
}


/*	The module with the given name was just unloaded.
	Make sure we have no dangling references. */

EXPORT(sqInt) moduleUnloaded(char *aModuleName) {
	if ((strcmp(aModuleName, "SecurityPlugin")) == 0) {
		sDSAfn = sHSAfn = sCCTPfn = sCCLOPfn = sCCSOTfn = 0;
	}
}

static sqInt msg(char *s) {
	fprintf(stderr, "\n%s: %s", moduleName, s);
}


/*	Convert the given internet network address (represented as a four-byte ByteArray) into a 32-bit integer. Fail if the given ptrToByteArray does not appear to point to a four-byte ByteArray. */

static sqInt netAddressToInt(unsigned char *  ptrToByteArray) {
	sqInt sz;

	sz = interpreterProxy->byteSizeOf((oopForPointer( ptrToByteArray ) - BASE_HEADER_SIZE));
	if (!(sz == 4)) {
		return interpreterProxy->primitiveFail();
	}
	return (((ptrToByteArray[3]) + ((ptrToByteArray[2]) << 8)) + ((ptrToByteArray[1]) << 16)) + ((ptrToByteArray[0]) << 24);
}


/*	If the security plugin can be loaded, use it to turn off socket access
	 If not, assume it's ok */

EXPORT(sqInt) primitiveDisableSocketAccess(void) {
	if (sDSAfn != 0) {
		((int (*) (void)) sDSAfn)();
	}
}

EXPORT(sqInt) primitiveHasSocketAccess(void) {
	sqInt hasAccess;

	if (sHSAfn != 0) {
		hasAccess =  ((int (*) (void)) sHSAfn)();
	} else {
		hasAccess = 1;
	}
	interpreterProxy->pop(1);
	interpreterProxy->pushBool(hasAccess);
}

EXPORT(sqInt) primitiveInitializeNetwork(void) {
	sqInt err;
	sqInt resolverSemaIndex;

	resolverSemaIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	err = sqNetworkInit(resolverSemaIndex);
	interpreterProxy->success(err == 0);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveResolverAbortLookup(void) {
	sqResolverAbort();
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveResolverAddressLookupResult(void) {
	sqInt s;
	sqInt sz;

	sz = sqResolverAddrLookupResultSize();
	if (!(interpreterProxy->failed())) {
		s = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classString(), sz);
		sqResolverAddrLookupResult((char *) interpreterProxy->firstIndexableField(s), sz);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, s);
	return null;
}

EXPORT(sqInt) primitiveResolverError(void) {
	sqInt _return_value;

	_return_value = interpreterProxy->integerObjectOf((sqResolverError()));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveResolverGetAddressInfoFamily(void) {
	sqInt family;
	sqInt _return_value;

	if (!(interpreterProxy->failed())) {
		family = sqResolverGetAddressInfoFamily();
		_return_value = interpreterProxy->integerObjectOf(family);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(1, _return_value);
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveResolverGetAddressInfo(void) {
	sqInt servSize;
	sqInt hostSize;
	char *hostName;
	char *servName;
	sqInt flags;
	sqInt family;
	sqInt type;
	sqInt protocol;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(5)));
	hostName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(5))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(4)));
	servName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(4))));
	flags = interpreterProxy->stackIntegerValue(3);
	family = interpreterProxy->stackIntegerValue(2);
	type = interpreterProxy->stackIntegerValue(1);
	protocol = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		hostSize = interpreterProxy->byteSizeOf((oopForPointer( hostName ) - BASE_HEADER_SIZE));
		servSize = interpreterProxy->byteSizeOf((oopForPointer( servName ) - BASE_HEADER_SIZE));
		sqResolverGetAddressInfoHostSizeServiceSizeFlagsFamilyTypeProtocol(hostName, hostSize, servName, servSize, flags, family, type, protocol);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(6);
	return null;
}

EXPORT(sqInt) primitiveResolverGetAddressInfoNext(void) {
	sqInt more;
	sqInt _return_value;

	more = sqResolverGetAddressInfoNext();
	if (interpreterProxy->failed()) {
		return null;
	}
	_return_value = (more) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveResolverGetAddressInfoProtocol(void) {
	sqInt protocol;
	sqInt _return_value;

	if (!(interpreterProxy->failed())) {
		protocol = sqResolverGetAddressInfoProtocol();
		_return_value = interpreterProxy->integerObjectOf(protocol);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(1, _return_value);
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveResolverGetAddressInfoResult(void) {
	sqInt addrSize;
	char *socketAddress;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	socketAddress = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		addrSize = interpreterProxy->byteSizeOf((oopForPointer( socketAddress ) - BASE_HEADER_SIZE));
		sqResolverGetAddressInfoResultSize(socketAddress, addrSize);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveResolverGetAddressInfoSize(void) {
	sqInt size;
	sqInt _return_value;

	if (!(interpreterProxy->failed())) {
		size = sqResolverGetAddressInfoSize();
		_return_value = interpreterProxy->integerObjectOf(size);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(1, _return_value);
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveResolverGetAddressInfoType(void) {
	sqInt type;
	sqInt _return_value;

	if (!(interpreterProxy->failed())) {
		type = sqResolverGetAddressInfoType();
		_return_value = interpreterProxy->integerObjectOf(type);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(1, _return_value);
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveResolverGetNameInfo(void) {
	char *addrBase;
	sqInt addrSize;
	sqInt socketAddress;
	sqInt flags;

	socketAddress = interpreterProxy->stackValue(1);
	flags = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		addrSize = interpreterProxy->byteSizeOf(socketAddress);
		addrBase = ((char *) (interpreterProxy->firstIndexableField(socketAddress)));
		sqResolverGetNameInfoSizeFlags(addrBase, addrSize, flags);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveResolverGetNameInfoHostResult(void) {
	sqInt addrSize;
	char *socketName;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	socketName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		addrSize = interpreterProxy->byteSizeOf((oopForPointer( socketName ) - BASE_HEADER_SIZE));
		sqResolverGetNameInfoHostResultSize(socketName, addrSize);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveResolverGetNameInfoHostSize(void) {
	sqInt size;
	sqInt _return_value;

	if (!(interpreterProxy->failed())) {
		size = sqResolverGetNameInfoHostSize();
		_return_value = interpreterProxy->integerObjectOf(size);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(1, _return_value);
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveResolverGetNameInfoServiceResult(void) {
	sqInt addrSize;
	char *socketName;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	socketName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		addrSize = interpreterProxy->byteSizeOf((oopForPointer( socketName ) - BASE_HEADER_SIZE));
		sqResolverGetNameInfoServiceResultSize(socketName, addrSize);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveResolverGetNameInfoServiceSize(void) {
	sqInt size;
	sqInt _return_value;

	if (!(interpreterProxy->failed())) {
		size = sqResolverGetNameInfoServiceSize();
		_return_value = interpreterProxy->integerObjectOf(size);
		if (interpreterProxy->failed()) {
			return null;
		}
		interpreterProxy->popthenPush(1, _return_value);
		return null;
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveResolverHostNameResult(void) {
	sqInt nameSize;
	char *nameString;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	nameString = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		nameSize = interpreterProxy->byteSizeOf((oopForPointer( nameString ) - BASE_HEADER_SIZE));
		sqResolverHostNameResultSize(nameString, nameSize);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveResolverHostNameSize(void) {
	sqInt size;
	sqInt _return_value;

	if (!(interpreterProxy->failed())) {
		size = sqResolverHostNameSize();
		if (!(interpreterProxy->failed())) {
			_return_value = interpreterProxy->integerObjectOf(size);
			if (interpreterProxy->failed()) {
				return null;
			}
			interpreterProxy->popthenPush(1, _return_value);
			return null;
		}
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveResolverLocalAddress(void) {
	sqInt addr;
	sqInt _return_value;

	addr = sqResolverLocalAddress();
	_return_value = intToNetAddress(addr);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveResolverNameLookupResult(void) {
	sqInt addr;
	sqInt _return_value;

	addr = sqResolverNameLookupResult();
	_return_value = intToNetAddress(addr);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveResolverStartAddressLookup(void) {
	sqInt addr;
	char *address;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	address = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	addr = netAddressToInt(((unsigned char *) address));
	if (!(interpreterProxy->failed())) {
		sqResolverStartAddrLookup(addr);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveResolverStartNameLookup(void) {
	sqInt sz;
	char *name;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	name = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	if (!(interpreterProxy->failed())) {
		sz = interpreterProxy->byteSizeOf((oopForPointer( name ) - BASE_HEADER_SIZE));
		sqResolverStartNameLookup(name, sz);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveResolverStatus(void) {
	sqInt status;
	sqInt _return_value;

	status = sqResolverStatus();
	_return_value = interpreterProxy->integerObjectOf(status);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(1, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketBindTo(void) {
	sqInt addrSize;
	char *addrBase;
	SocketPtr s;
	sqInt socket;
	sqInt socketAddress;

	socket = interpreterProxy->stackValue(1);
	socketAddress = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	addrSize = interpreterProxy->byteSizeOf(socketAddress);
	addrBase = ((char *) (interpreterProxy->firstIndexableField(socketAddress)));
	if (!(interpreterProxy->failed())) {
		sqSocketBindToAddressSize(s, addrBase, addrSize);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveSocketBindToPort(void) {
	sqInt addr;
	SocketPtr s;
	sqInt socket;
	char *address;
	sqInt port;

	socket = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	address = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	port = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	addr = netAddressToInt(((unsigned char *) address));
	s = socketValueOf(socket);
	if (!(interpreterProxy->failed())) {
		sqSocketBindToPort(s, addr, port);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitiveSocketConnectTo(void) {
	sqInt addrSize;
	char *addrBase;
	SocketPtr s;
	sqInt socket;
	sqInt socketAddress;

	socket = interpreterProxy->stackValue(1);
	socketAddress = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	addrSize = interpreterProxy->byteSizeOf(socketAddress);
	addrBase = ((char *) (interpreterProxy->firstIndexableField(socketAddress)));
	if (!(interpreterProxy->failed())) {
		sqSocketConnectToAddressSize(s, addrBase, addrSize);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveSocketConnectToPort(void) {
	sqInt okToConnect;
	sqInt addr;
	SocketPtr s;
	sqInt socket;
	char *address;
	sqInt port;

	socket = interpreterProxy->stackValue(2);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	address = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	port = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}

	/* If the security plugin can be loaded, use it to check for permission.
	If not, assume it's ok */

	addr = netAddressToInt(((unsigned char *) address));
	if (sCCTPfn != 0) {
		okToConnect =  ((int (*) (int, int)) sCCTPfn)(addr, port);
		if (!(okToConnect)) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	s = socketValueOf(socket);
	if (!(interpreterProxy->failed())) {
		sqSocketConnectToPort(s, addr, port);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}

EXPORT(sqInt) primitiveSocketGetOptions(void) {
	sqInt errorCode;
	char *optionNameStart;
	sqInt optionNameSize;
	sqInt returnedValue;
	sqInt results;
	SocketPtr s;
	sqInt socket;
	sqInt optionName;

	socket = interpreterProxy->stackValue(1);
	optionName = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	interpreterProxy->success(interpreterProxy->isBytes(optionName));
	optionNameStart = ((char *) (interpreterProxy->firstIndexableField(optionName)));
	optionNameSize = interpreterProxy->slotSizeOf(optionName);
	if (interpreterProxy->failed()) {
		return null;
	}
	returnedValue = 0;
	errorCode = sqSocketGetOptionsoptionNameStartoptionNameSizereturnedValue(s, optionNameStart, optionNameSize, &returnedValue);
	interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf(returnedValue));
	interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf(errorCode));
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	results = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, results, interpreterProxy->popRemappableOop());
	interpreterProxy->storePointerofObjectwithValue(1, results, interpreterProxy->popRemappableOop());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(3, results);
	return null;
}


/*	one part of the wierdass dual prim primitiveSocketListenOnPort which 
	was warped by some demented evil person determined to twist the very 
	nature of reality */

EXPORT(sqInt) primitiveSocketListenOnPort(void) {
	sqInt okToListen;
	SocketPtr  s;
	sqInt socket;
	sqInt port;

	socket = interpreterProxy->stackValue(1);
	port = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}

	/* If the security plugin can be loaded, use it to check for permission.
	If  not, assume it's ok */

	s = socketValueOf(socket);
	if (sCCLOPfn != 0) {
		okToListen =  ((int (*) (SocketPtr, int)) sCCLOPfn)(s, port);
		if (!(okToListen)) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	if (!(interpreterProxy->failed())) {
		sqSocketListenOnPort(s, port);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	second part of the wierdass dual prim primitiveSocketListenOnPort 
	which was warped by some demented evil person determined to twist the 
	very nature of reality */

EXPORT(sqInt) primitiveSocketListenOnPortBacklog(void) {
	sqInt okToListen;
	SocketPtr s;
	sqInt socket;
	sqInt port;
	sqInt backlog;

	socket = interpreterProxy->stackValue(2);
	port = interpreterProxy->stackIntegerValue(1);
	backlog = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}

	/* If the security plugin can be loaded, use it to check for permission.
	If not, assume it's ok */

	s = socketValueOf(socket);
	if (sCCLOPfn != 0) {
		okToListen =  ((int (*) (SocketPtr, int)) sCCLOPfn)(s, port);
		if (!(okToListen)) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	sqSocketListenOnPortBacklogSize(s, port, backlog);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(3);
	return null;
}


/*	Bind a socket to the given port and interface address with no more than backlog pending connections.  The socket can be UDP, in which case the backlog should be specified as zero. */

EXPORT(sqInt) primitiveSocketListenOnPortBacklogInterface(void) {
	sqInt okToListen;
	sqInt addr;
	SocketPtr s;
	sqInt socket;
	sqInt port;
	sqInt backlog;
	char *ifAddr;

	socket = interpreterProxy->stackValue(3);
	port = interpreterProxy->stackIntegerValue(2);
	backlog = interpreterProxy->stackIntegerValue(1);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	ifAddr = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}

	/* If the security plugin can be loaded, use it to check for permission.
	If  not, assume it's ok */

	s = socketValueOf(socket);
	if (sCCLOPfn != 0) {
		okToListen =  ((int (*) (SocketPtr, int)) sCCLOPfn)(s, port);
		if (!(okToListen)) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	addr = netAddressToInt(((unsigned char *) ifAddr));
	sqSocketListenOnPortBacklogSizeInterface(s, port, backlog, addr);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(4);
	return null;
}

EXPORT(sqInt) primitiveSocketListenWithBacklog(void) {
	SocketPtr s;
	sqInt socket;
	sqInt backlogSize;

	socket = interpreterProxy->stackValue(1);
	backlogSize = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	if (!(interpreterProxy->failed())) {
		sqSocketListenBacklog(s, backlogSize);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveSocketLocalAddressResult(void) {
	sqInt addrSize;
	char *addrBase;
	SocketPtr s;
	sqInt socket;
	sqInt socketAddress;

	socket = interpreterProxy->stackValue(1);
	socketAddress = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	addrSize = interpreterProxy->byteSizeOf(socketAddress);
	addrBase = ((char *) (interpreterProxy->firstIndexableField(socketAddress)));
	if (!(interpreterProxy->failed())) {
		sqSocketLocalAddressResultSize(s, addrBase, addrSize);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveSocketReceiveDataBufCount(void) {
	char *arrayBase;
	char *bufStart;
	sqInt byteSize;
	sqInt bytesReceived;
	SocketPtr s;
	sqInt socket;
	sqInt array;
	sqInt startIndex;
	sqInt count;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(3);
	array = interpreterProxy->stackValue(2);
	startIndex = interpreterProxy->stackIntegerValue(1);
	count = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}

	/* buffer can be any indexable words or bytes object */

	s = socketValueOf(socket);
	interpreterProxy->success(interpreterProxy->isWordsOrBytes(array));
	if (interpreterProxy->isWords(array)) {
		byteSize = 4;
	} else {
		byteSize = 1;
	}
	interpreterProxy->success((startIndex >= 1) && ((count >= 0) && (((startIndex + count) - 1) <= (interpreterProxy->slotSizeOf(array)))));
	if (!(interpreterProxy->failed())) {

		/* Note: adjust bufStart for zero-origin indexing */

		arrayBase = ((char *) (interpreterProxy->firstIndexableField(array)));
		bufStart = arrayBase + ((startIndex - 1) * byteSize);
		bytesReceived = sqSocketReceiveDataBufCount(s, bufStart, count * byteSize);
	}
	_return_value = interpreterProxy->integerObjectOf((bytesReceived / byteSize));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketReceiveUDPDataBufCount(void) {
	char *arrayBase;
	sqInt moreFlag;
	char *bufStart;
	sqInt port;
	sqInt address;
	sqInt byteSize;
	sqInt bytesReceived;
	sqInt results;
	SocketPtr s;
	sqInt socket;
	sqInt array;
	sqInt startIndex;
	sqInt count;

	socket = interpreterProxy->stackValue(3);
	array = interpreterProxy->stackValue(2);
	startIndex = interpreterProxy->stackIntegerValue(1);
	count = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}

	/* buffer can be any indexable words or bytes object */

	s = socketValueOf(socket);
	interpreterProxy->success(interpreterProxy->isWordsOrBytes(array));
	if (interpreterProxy->isWords(array)) {
		byteSize = 4;
	} else {
		byteSize = 1;
	}
	interpreterProxy->success((startIndex >= 1) && ((count >= 0) && (((startIndex + count) - 1) <= (interpreterProxy->slotSizeOf(array)))));
	if (!(interpreterProxy->failed())) {

		/* Note: adjust bufStart for zero-origin indexing */

		arrayBase = ((char *) (interpreterProxy->firstIndexableField(array)));

		/* allocate storage for results, remapping newly allocated
			 oops in case GC happens during allocation */

		bufStart = arrayBase + ((startIndex - 1) * byteSize);
		address = 0;
		port = 0;
		moreFlag = 0;
		bytesReceived = sqSocketReceiveUDPDataBufCountaddressportmoreFlag(s, bufStart, count * byteSize, &address, &port, &moreFlag);
		interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf(port));
		interpreterProxy->pushRemappableOop(intToNetAddress(address));
		interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf((bytesReceived / byteSize)));
		interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 4));
		results = interpreterProxy->popRemappableOop();
		interpreterProxy->storePointerofObjectwithValue(0, results, interpreterProxy->popRemappableOop());
		interpreterProxy->storePointerofObjectwithValue(1, results, interpreterProxy->popRemappableOop());
		interpreterProxy->storePointerofObjectwithValue(2, results, interpreterProxy->popRemappableOop());
		if (moreFlag) {
			interpreterProxy->storePointerofObjectwithValue(3, results, interpreterProxy->trueObject());
		} else {
			interpreterProxy->storePointerofObjectwithValue(3, results, interpreterProxy->falseObject());
		}
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, results);
	return null;
}

EXPORT(sqInt) primitiveSocketRemoteAddressResult(void) {
	sqInt addrSize;
	char *addrBase;
	SocketPtr s;
	sqInt socket;
	sqInt socketAddress;

	socket = interpreterProxy->stackValue(1);
	socketAddress = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	addrSize = interpreterProxy->byteSizeOf(socketAddress);
	addrBase = ((char *) (interpreterProxy->firstIndexableField(socketAddress)));
	if (!(interpreterProxy->failed())) {
		sqSocketRemoteAddressResultSize(s, addrBase, addrSize);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}

EXPORT(sqInt) primitiveSocketSendDataBufCount(void) {
	sqInt bytesSent;
	char *arrayBase;
	char *bufStart;
	sqInt byteSize;
	SocketPtr s;
	sqInt socket;
	sqInt array;
	sqInt startIndex;
	sqInt count;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(3);
	array = interpreterProxy->stackValue(2);
	startIndex = interpreterProxy->stackIntegerValue(1);
	count = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}

	/* buffer can be any indexable words or bytes object except CompiledMethod  */

	s = socketValueOf(socket);
	interpreterProxy->success(interpreterProxy->isWordsOrBytes(array));
	if (interpreterProxy->isWords(array)) {
		byteSize = 4;
	} else {
		byteSize = 1;
	}
	interpreterProxy->success((startIndex >= 1) && ((count >= 0) && (((startIndex + count) - 1) <= (interpreterProxy->slotSizeOf(array)))));
	if (!(interpreterProxy->failed())) {

		/* Note: adjust bufStart for zero-origin indexing */

		arrayBase = ((char *) (interpreterProxy->firstIndexableField(array)));
		bufStart = arrayBase + ((startIndex - 1) * byteSize);
		bytesSent = sqSocketSendDataBufCount(s, bufStart, count * byteSize);
	}
	_return_value = interpreterProxy->integerObjectOf((bytesSent / byteSize));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketSendUDPDataBufCount(void) {
	SocketPtr s;
	sqInt bytesSent;
	char *arrayBase;
	char *bufStart;
	sqInt address;
	sqInt byteSize;
	sqInt socket;
	sqInt array;
	char *hostAddress;
	sqInt portNumber;
	sqInt startIndex;
	sqInt count;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(5);
	array = interpreterProxy->stackValue(4);
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(3)));
	hostAddress = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(3))));
	portNumber = interpreterProxy->stackIntegerValue(2);
	startIndex = interpreterProxy->stackIntegerValue(1);
	count = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}

	/* buffer can be any indexable words or bytes object except CompiledMethod  */

	s = socketValueOf(socket);
	interpreterProxy->success(interpreterProxy->isWordsOrBytes(array));
	if (interpreterProxy->isWords(array)) {
		byteSize = 4;
	} else {
		byteSize = 1;
	}
	interpreterProxy->success((startIndex >= 1) && ((count >= 0) && (((startIndex + count) - 1) <= (interpreterProxy->slotSizeOf(array)))));
	if (!(interpreterProxy->failed())) {

		/* Note: adjust bufStart for zero-origin indexing */

		arrayBase = ((char *) (interpreterProxy->firstIndexableField(array)));
		bufStart = arrayBase + ((startIndex - 1) * byteSize);
		address = netAddressToInt(((unsigned char *) hostAddress));
		bytesSent = sqSockettoHostportSendDataBufCount(s, address, portNumber, bufStart, count * byteSize);
	}
	_return_value = interpreterProxy->integerObjectOf((bytesSent / byteSize));
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(7, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketSetOptions(void) {
	sqInt errorCode;
	sqInt results;
	char *optionNameStart;
	char *optionValueStart;
	sqInt optionNameSize;
	sqInt optionValueSize;
	sqInt returnedValue;
	SocketPtr s;
	sqInt socket;
	sqInt optionName;
	sqInt optionValue;

	socket = interpreterProxy->stackValue(2);
	optionName = interpreterProxy->stackValue(1);
	optionValue = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	interpreterProxy->success(interpreterProxy->isBytes(optionName));
	optionNameStart = ((char *) (interpreterProxy->firstIndexableField(optionName)));
	optionNameSize = interpreterProxy->slotSizeOf(optionName);
	interpreterProxy->success(interpreterProxy->isBytes(optionValue));
	optionValueStart = ((char *) (interpreterProxy->firstIndexableField(optionValue)));
	optionValueSize = interpreterProxy->slotSizeOf(optionValue);
	if (interpreterProxy->failed()) {
		return null;
	}
	returnedValue = 0;
	errorCode = sqSocketSetOptionsoptionNameStartoptionNameSizeoptionValueStartoptionValueSizereturnedValue(s, optionNameStart, optionNameSize, optionValueStart, optionValueSize, &returnedValue);
	interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf(returnedValue));
	interpreterProxy->pushRemappableOop(interpreterProxy->integerObjectOf(errorCode));
	interpreterProxy->pushRemappableOop(interpreterProxy->instantiateClassindexableSize(interpreterProxy->classArray(), 2));
	results = interpreterProxy->popRemappableOop();
	interpreterProxy->storePointerofObjectwithValue(0, results, interpreterProxy->popRemappableOop());
	interpreterProxy->storePointerofObjectwithValue(1, results, interpreterProxy->popRemappableOop());
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(4, results);
	return null;
}

EXPORT(sqInt) primitiveSocketAbortConnection(void) {
	SocketPtr  s;
	sqInt socket;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	if (!(interpreterProxy->failed())) {
		sqSocketAbortConnection(s);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveSocketAccept(void) {
	sqInt socketOop;
	SocketPtr  serverSocket;
	SocketPtr  s;
	sqInt sockHandle;
	sqInt recvBufSize;
	sqInt sendBufSize;
	sqInt semaIndex;

	sockHandle = interpreterProxy->stackValue(3);
	recvBufSize = interpreterProxy->stackIntegerValue(2);
	sendBufSize = interpreterProxy->stackIntegerValue(1);
	semaIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	serverSocket = socketValueOf(sockHandle);
	if (!(interpreterProxy->failed())) {
		socketOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), socketRecordSize());
		s = socketValueOf(socketOop);
		sqSocketAcceptFromRecvBytesSendBytesSemaID(s, serverSocket, recvBufSize, sendBufSize, semaIndex);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(5, socketOop);
	return null;
}

EXPORT(sqInt) primitiveSocketAccept3Semaphores(void) {
	sqInt socketOop;
	SocketPtr  serverSocket;
	SocketPtr  s;
	sqInt sockHandle;
	sqInt recvBufSize;
	sqInt sendBufSize;
	sqInt semaIndex;
	sqInt aReadSema;
	sqInt aWriteSema;

	sockHandle = interpreterProxy->stackValue(5);
	recvBufSize = interpreterProxy->stackIntegerValue(4);
	sendBufSize = interpreterProxy->stackIntegerValue(3);
	semaIndex = interpreterProxy->stackIntegerValue(2);
	aReadSema = interpreterProxy->stackIntegerValue(1);
	aWriteSema = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	serverSocket = socketValueOf(sockHandle);
	if (!(interpreterProxy->failed())) {
		socketOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), socketRecordSize());
		s = socketValueOf(socketOop);
		sqSocketAcceptFromRecvBytesSendBytesSemaIDReadSemaIDWriteSemaID(s, serverSocket, recvBufSize, sendBufSize, semaIndex, aReadSema, aWriteSema);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(7, socketOop);
	return null;
}

EXPORT(sqInt) primitiveSocketAddressGetPort(void) {
	sqInt addr;
	char *addrBase;
	sqInt port;
	sqInt addrSize;
	sqInt _return_value;

	addr = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	addrSize = interpreterProxy->byteSizeOf(addr);
	addrBase = ((char *) (interpreterProxy->firstIndexableField(addr)));
	if (!(interpreterProxy->failed())) {
		port = sqSocketAddressSizeGetPort(addrBase, addrSize);
		if (!(interpreterProxy->failed())) {
			_return_value = interpreterProxy->integerObjectOf(port);
			if (interpreterProxy->failed()) {
				return null;
			}
			interpreterProxy->popthenPush(1, _return_value);
			return null;
		}
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	return null;
}

EXPORT(sqInt) primitiveSocketAddressSetPort(void) {
	sqInt addr;
	char *addrBase;
	sqInt addrSize;
	sqInt portNumber;

	portNumber = interpreterProxy->stackIntegerValue(0);
	addr = interpreterProxy->stackValue(1);
	if (interpreterProxy->failed()) {
		return null;
	}
	addrSize = interpreterProxy->byteSizeOf(addr);
	addrBase = ((char *) (interpreterProxy->firstIndexableField(addr)));
	if (!(interpreterProxy->failed())) {
		sqSocketAddressSizeSetPort(addrBase, addrSize, portNumber);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveSocketCloseConnection(void) {
	SocketPtr  s;
	sqInt socket;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	if (!(interpreterProxy->failed())) {
		sqSocketCloseConnection(s);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveSocketConnectionStatus(void) {
	sqInt status;
	SocketPtr  s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	if (!(interpreterProxy->failed())) {
		status = sqSocketConnectionStatus(s);
	}
	_return_value = interpreterProxy->integerObjectOf(status);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketCreate(void) {
	sqInt socketOop;
	sqInt okToCreate;
	SocketPtr  s;
	sqInt netType;
	sqInt socketType;
	sqInt recvBufSize;
	sqInt sendBufSize;
	sqInt semaIndex;

	netType = interpreterProxy->stackIntegerValue(4);
	socketType = interpreterProxy->stackIntegerValue(3);
	recvBufSize = interpreterProxy->stackIntegerValue(2);
	sendBufSize = interpreterProxy->stackIntegerValue(1);
	semaIndex = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (sCCSOTfn != 0) {
		okToCreate =  ((int (*) (int, int)) sCCSOTfn)(netType, socketType);
		if (!(okToCreate)) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	socketOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), socketRecordSize());
	s = socketValueOf(socketOop);
	sqSocketCreateNetTypeSocketTypeRecvBytesSendBytesSemaID(s, netType, socketType, recvBufSize, sendBufSize, semaIndex);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(6, socketOop);
	return null;
}

EXPORT(sqInt) primitiveSocketCreate3Semaphores(void) {
	sqInt socketOop;
	sqInt okToCreate;
	SocketPtr  s;
	sqInt netType;
	sqInt socketType;
	sqInt recvBufSize;
	sqInt sendBufSize;
	sqInt semaIndex;
	sqInt aReadSema;
	sqInt aWriteSema;

	netType = interpreterProxy->stackIntegerValue(6);
	socketType = interpreterProxy->stackIntegerValue(5);
	recvBufSize = interpreterProxy->stackIntegerValue(4);
	sendBufSize = interpreterProxy->stackIntegerValue(3);
	semaIndex = interpreterProxy->stackIntegerValue(2);
	aReadSema = interpreterProxy->stackIntegerValue(1);
	aWriteSema = interpreterProxy->stackIntegerValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	if (sCCSOTfn != 0) {
		okToCreate =  ((int (*) (int, int)) sCCSOTfn)(netType, socketType);
		if (!(okToCreate)) {
			interpreterProxy->primitiveFail();
			return null;
		}
	}
	socketOop = interpreterProxy->instantiateClassindexableSize(interpreterProxy->classByteArray(), socketRecordSize());
	s = socketValueOf(socketOop);
	sqSocketCreateNetTypeSocketTypeRecvBytesSendBytesSemaIDReadSemaIDWriteSemaID(s, netType, socketType, recvBufSize, sendBufSize, semaIndex, aReadSema, aWriteSema);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(8, socketOop);
	return null;
}

EXPORT(sqInt) primitiveSocketDestroy(void) {
	SocketPtr s;
	sqInt socket;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	if (!(interpreterProxy->failed())) {
		sqSocketDestroy(s);
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(1);
	return null;
}

EXPORT(sqInt) primitiveSocketError(void) {
	sqInt err;
	SocketPtr  s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	if (!(interpreterProxy->failed())) {
		err = sqSocketError(s);
	}
	_return_value = interpreterProxy->integerObjectOf(err);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Backward compatibility */

EXPORT(sqInt) primitiveSocketListenWithOrWithoutBacklog(void) {
	if ((interpreterProxy->methodArgumentCount()) == 2) {
		return primitiveSocketListenOnPort();
	} else {
		return primitiveSocketListenOnPortBacklog();
	}
}

EXPORT(sqInt) primitiveSocketLocalAddress(void) {
	sqInt addr;
	SocketPtr s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	addr = sqSocketLocalAddress(s);
	_return_value = intToNetAddress(addr);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketLocalAddressSize(void) {
	sqInt size;
	SocketPtr s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	if (interpreterProxy->failed()) {
		return null;
	}
	size = sqSocketLocalAddressSize(s);
	if (interpreterProxy->failed()) {
		return null;
	}
	_return_value = interpreterProxy->integerObjectOf(size);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketLocalPort(void) {
	sqInt port;
	SocketPtr  s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	port = sqSocketLocalPort(s);
	_return_value = interpreterProxy->integerObjectOf(port);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketReceiveDataAvailable(void) {
	sqInt dataIsAvailable;
	SocketPtr s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	dataIsAvailable = sqSocketReceiveDataAvailable(s);
	_return_value = (dataIsAvailable) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketRemoteAddress(void) {
	sqInt addr;
	SocketPtr s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	addr = sqSocketRemoteAddress(s);
	_return_value = intToNetAddress(addr);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketRemoteAddressSize(void) {
	sqInt size;
	SocketPtr s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	if (interpreterProxy->failed()) {
		return null;
	}
	size = sqSocketRemoteAddressSize(s);
	if (interpreterProxy->failed()) {
		return null;
	}
	_return_value = interpreterProxy->integerObjectOf(size);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketRemotePort(void) {
	sqInt port;
	SocketPtr s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	port = sqSocketRemotePort(s);
	_return_value = interpreterProxy->integerObjectOf(port);
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}

EXPORT(sqInt) primitiveSocketSendDone(void) {
	sqInt done;
	SocketPtr s;
	sqInt socket;
	sqInt _return_value;

	socket = interpreterProxy->stackValue(0);
	if (interpreterProxy->failed()) {
		return null;
	}
	s = socketValueOf(socket);
	done = sqSocketSendDone(s);
	_return_value = (done) ? interpreterProxy->trueObject(): interpreterProxy->falseObject();
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->popthenPush(2, _return_value);
	return null;
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter) {
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}

EXPORT(sqInt) shutdownModule(void) {
	return socketShutdown();
}


/*	Return the size of a Smalltalk socket record in bytes. */

static sqInt socketRecordSize(void) {
	return sizeof(SQSocket);
}


/*	Return a pointer to the first byte of of the socket record within the  
	given Smalltalk object, or nil if socketOop is not a socket record. */

static SQSocket * socketValueOf(sqInt socketOop) {
	void *socketIndex;

	interpreterProxy->success((interpreterProxy->isBytes(socketOop)) && ((interpreterProxy->byteSizeOf(socketOop)) == (socketRecordSize())));
	if (interpreterProxy->failed()) {
		return null;
	} else {
		socketIndex = ((void *) (interpreterProxy->firstIndexableField(socketOop)));
		return (SQSocket *) socketIndex;
	}
}

static sqInt sqAssert(sqInt aBool) {
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN


void* SocketPlugin_exports[][3] = {
	{"SocketPlugin", "primitiveSocketRemoteAddressResult", (void*)primitiveSocketRemoteAddressResult},
	{"SocketPlugin", "primitiveSocketListenOnPort", (void*)primitiveSocketListenOnPort},
	{"SocketPlugin", "primitiveSocketRemoteAddress", (void*)primitiveSocketRemoteAddress},
	{"SocketPlugin", "getModuleName", (void*)getModuleName},
	{"SocketPlugin", "primitiveSocketConnectToPort", (void*)primitiveSocketConnectToPort},
	{"SocketPlugin", "primitiveResolverGetAddressInfoProtocol", (void*)primitiveResolverGetAddressInfoProtocol},
	{"SocketPlugin", "primitiveSocketListenOnPortBacklog", (void*)primitiveSocketListenOnPortBacklog},
	{"SocketPlugin", "primitiveSocketSendDone", (void*)primitiveSocketSendDone},
	{"SocketPlugin", "primitiveSocketListenWithBacklog", (void*)primitiveSocketListenWithBacklog},
	{"SocketPlugin", "primitiveDisableSocketAccess", (void*)primitiveDisableSocketAccess},
	{"SocketPlugin", "primitiveHasSocketAccess", (void*)primitiveHasSocketAccess},
	{"SocketPlugin", "primitiveSocketRemotePort", (void*)primitiveSocketRemotePort},
	{"SocketPlugin", "primitiveSocketBindToPort", (void*)primitiveSocketBindToPort},
	{"SocketPlugin", "primitiveResolverGetNameInfoHostResult", (void*)primitiveResolverGetNameInfoHostResult},
	{"SocketPlugin", "primitiveSocketReceiveDataBufCount", (void*)primitiveSocketReceiveDataBufCount},
	{"SocketPlugin", "primitiveResolverStartNameLookup", (void*)primitiveResolverStartNameLookup},
	{"SocketPlugin", "primitiveSocketLocalAddress", (void*)primitiveSocketLocalAddress},
	{"SocketPlugin", "primitiveSocketRemoteAddressSize", (void*)primitiveSocketRemoteAddressSize},
	{"SocketPlugin", "primitiveResolverHostNameResult", (void*)primitiveResolverHostNameResult},
	{"SocketPlugin", "primitiveResolverLocalAddress", (void*)primitiveResolverLocalAddress},
	{"SocketPlugin", "primitiveSocketLocalAddressResult", (void*)primitiveSocketLocalAddressResult},
	{"SocketPlugin", "primitiveSocketLocalPort", (void*)primitiveSocketLocalPort},
	{"SocketPlugin", "primitiveSocketCreate", (void*)primitiveSocketCreate},
	{"SocketPlugin", "primitiveResolverGetAddressInfoNext", (void*)primitiveResolverGetAddressInfoNext},
	{"SocketPlugin", "primitiveResolverGetAddressInfoFamily", (void*)primitiveResolverGetAddressInfoFamily},
	{"SocketPlugin", "primitiveResolverGetAddressInfo", (void*)primitiveResolverGetAddressInfo},
	{"SocketPlugin", "primitiveResolverHostNameSize", (void*)primitiveResolverHostNameSize},
	{"SocketPlugin", "primitiveSocketDestroy", (void*)primitiveSocketDestroy},
	{"SocketPlugin", "primitiveSocketSetOptions", (void*)primitiveSocketSetOptions},
	{"SocketPlugin", "primitiveSocketListenOnPortBacklogInterface", (void*)primitiveSocketListenOnPortBacklogInterface},
	{"SocketPlugin", "primitiveResolverStartAddressLookup", (void*)primitiveResolverStartAddressLookup},
	{"SocketPlugin", "primitiveSocketSendDataBufCount", (void*)primitiveSocketSendDataBufCount},
	{"SocketPlugin", "primitiveResolverGetAddressInfoType", (void*)primitiveResolverGetAddressInfoType},
	{"SocketPlugin", "primitiveSocketAccept", (void*)primitiveSocketAccept},
	{"SocketPlugin", "moduleUnloaded", (void*)moduleUnloaded},
	{"SocketPlugin", "primitiveSocketBindTo", (void*)primitiveSocketBindTo},
	{"SocketPlugin", "primitiveSocketError", (void*)primitiveSocketError},
	{"SocketPlugin", "primitiveSocketLocalAddressSize", (void*)primitiveSocketLocalAddressSize},
	{"SocketPlugin", "primitiveResolverAddressLookupResult", (void*)primitiveResolverAddressLookupResult},
	{"SocketPlugin", "primitiveResolverGetNameInfo", (void*)primitiveResolverGetNameInfo},
	{"SocketPlugin", "primitiveSocketConnectTo", (void*)primitiveSocketConnectTo},
	{"SocketPlugin", "setInterpreter", (void*)setInterpreter},
	{"SocketPlugin", "primitiveResolverGetNameInfoHostSize", (void*)primitiveResolverGetNameInfoHostSize},
	{"SocketPlugin", "primitiveSocketReceiveDataAvailable", (void*)primitiveSocketReceiveDataAvailable},
	{"SocketPlugin", "primitiveSocketReceiveUDPDataBufCount", (void*)primitiveSocketReceiveUDPDataBufCount},
	{"SocketPlugin", "primitiveSocketGetOptions", (void*)primitiveSocketGetOptions},
	{"SocketPlugin", "shutdownModule", (void*)shutdownModule},
	{"SocketPlugin", "primitiveSocketAbortConnection", (void*)primitiveSocketAbortConnection},
	{"SocketPlugin", "primitiveResolverGetAddressInfoResult", (void*)primitiveResolverGetAddressInfoResult},
	{"SocketPlugin", "primitiveSocketCloseConnection", (void*)primitiveSocketCloseConnection},
	{"SocketPlugin", "primitiveResolverGetNameInfoServiceResult", (void*)primitiveResolverGetNameInfoServiceResult},
	{"SocketPlugin", "primitiveResolverNameLookupResult", (void*)primitiveResolverNameLookupResult},
	{"SocketPlugin", "initialiseModule", (void*)initialiseModule},
	{"SocketPlugin", "primitiveResolverStatus", (void*)primitiveResolverStatus},
	{"SocketPlugin", "primitiveResolverAbortLookup", (void*)primitiveResolverAbortLookup},
	{"SocketPlugin", "primitiveSocketConnectionStatus", (void*)primitiveSocketConnectionStatus},
	{"SocketPlugin", "primitiveResolverGetAddressInfoSize", (void*)primitiveResolverGetAddressInfoSize},
	{"SocketPlugin", "primitiveSocketAccept3Semaphores", (void*)primitiveSocketAccept3Semaphores},
	{"SocketPlugin", "primitiveSocketAddressGetPort", (void*)primitiveSocketAddressGetPort},
	{"SocketPlugin", "primitiveSocketAddressSetPort", (void*)primitiveSocketAddressSetPort},
	{"SocketPlugin", "primitiveInitializeNetwork", (void*)primitiveInitializeNetwork},
	{"SocketPlugin", "primitiveSocketSendUDPDataBufCount", (void*)primitiveSocketSendUDPDataBufCount},
	{"SocketPlugin", "primitiveResolverError", (void*)primitiveResolverError},
	{"SocketPlugin", "primitiveSocketListenWithOrWithoutBacklog", (void*)primitiveSocketListenWithOrWithoutBacklog},
	{"SocketPlugin", "primitiveSocketCreate3Semaphores", (void*)primitiveSocketCreate3Semaphores},
	{"SocketPlugin", "primitiveResolverGetNameInfoServiceSize", (void*)primitiveResolverGetNameInfoServiceSize},
	{NULL, NULL, NULL}
};


#endif /* ifdef SQ_BUILTIN_PLUGIN */
