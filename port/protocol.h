#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

typedef enum _b
{
    _false = 0,
    _true
} Bool;

/********************************************************************
 * This function receives a message and forwards to Trigger
 * 
 * Inputs:
 *  - Trigger
 ********************************************************************/
Bool StartReceiving(Trigger trigger);

/********************************************************************
 * This function flushes a message to an output
 * 
 * Inputs:
 *  - Message
 ********************************************************************/
void Flush(Message message);

#endif