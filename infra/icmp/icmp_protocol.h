#ifndef __ICMP_PROTOCOL_H__
#define __ICMP_PROTOCOL_H__

#include "listener.h"

#define NewICMPListener NewListener(&ICMPStartReceiving, &ICMPFlush)
#define StartICMPListening(listener) StartListening(listener, "TODO!!")

/********************************************************************
 * This function flushes a message to an output
 * 
 * Inputs:
 *  - Message
 ********************************************************************/
void ICMPFlush(Message message);

/********************************************************************
 * This function receives a message and forwards to Listener
 * 
 * Inputs:
 *  - Listener
 ********************************************************************/
Bool ICMPStartReceiving(Listener listener);

#endif