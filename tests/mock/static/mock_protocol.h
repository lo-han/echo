#ifndef __MOCK_PROTOCOL_H__
#define __MOCK_PROTOCOL_H__

#include "listener.h"

#define NewMockListener() NewListener(&MockStartReceiving, &MockFlush)
#define StartMockListening(listener) StartListening(listener, "HELLO WORLD\0")

/********************************************************************
 * This function flushes a message to an output
 * 
 * Inputs:
 *  - Message
 ********************************************************************/
void MockFlush(Message message);

/********************************************************************
 * This function receives a message and forwards to Listener
 * 
 * Inputs:
 *  - Listener
 ********************************************************************/
Bool MockStartReceiving(Listener listener);

#endif