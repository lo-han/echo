#ifndef __ICMP_PROTOCOL_H__
#define __ICMP_PROTOCOL_H__

#include "listener.h"

#define NewICMPListener NewListener(&ICMPStartReceiving, &ICMPFlush)

/********************************************************************
 * This function receives a message and forwards to Listener
 *
 * Outputs:
 *  - Message
 ********************************************************************/
Message ICMPStartReceiving();

/********************************************************************
 * This function flushes a message to an output
 *
 * Inputs:
 *  - Message
 ********************************************************************/
void ICMPFlush(Message message);

#endif