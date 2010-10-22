/******************************************************************************
 *  Copyright (c) 2008 - 2010 IBM Corporation and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *    David Ungar, IBM Research - Initial Implementation
 *    Sam Adams, IBM Research - Initial Implementation
 *    Stefan Marr, Vrije Universiteit Brussel - Port to x86 Multi-Core Systems
 ******************************************************************************/


#include "headers.h"

void Shared_Memory_Message_Queue::buffered_send_buffer(void* p, int size) {
  buffered_channel.send(p, size);
}


void* Shared_Memory_Message_Queue::buffered_receive_from_anywhere(bool wait, Logical_Core** buffer_owner, Logical_Core* const me) {
  do {
    size_t size;
    if (me->message_queue.buffered_channel.hasData()) {
      *buffer_owner = me;
      return (void*)me->message_queue.buffered_channel.receive(size);
    }
  }
  while (wait);
  *buffer_owner = NULL;
  return NULL;
}


void Shared_Memory_Message_Queue::release_oldest_buffer(void* buffer_to_be_released_for_debugging) {
  buffered_channel.releaseOldest(buffer_to_be_released_for_debugging);
}



# include <signal.h>


void Shared_Memory_Message_Queue::send_message(abstractMessage_class* msg) {
  Message_Stats::collect_send_msg_stats(msg->header);
  bool verbose = false;
  switch(msg->header) {
      // case Message_Statics::requestSafepointMessage:
      // case Message_Statics::noMessage:
    case Message_Statics::addObjectFromSnapshotMessage:
    case Message_Statics::addObjectFromSnapshotResponse:
    case Message_Statics::broadcastInterpreterDatumMessage:
      verbose = false;
  }
  
  if (verbose) lprintf( "send_message about to send header %d, three words: 0x%x, 0x%x, 0x%x\n",
                       msg->header, ((int*)msg)[0], ((int*)msg)[1], ((int*)msg)[2]);
  
  
  if (verbose) lprintf( "send_message about to send to %d, size: %d bytes, three words: 0x%x, 0x%x, 0x%x\n",
                       cpu_core_my_rank(), msg->size_for_transmission_and_copying(), ((int*)msg)[0], ((int*)msg)[1], ((int*)msg)[2]);
  
  buffered_send_buffer(msg, msg->size_for_transmission_and_copying());
  
  if (verbose) lprintf( "send_message sent\n");
}
