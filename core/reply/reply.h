#ifndef __REPLY_H__
#define __REPLY_H__

typedef char *Message;

typedef struct _reply *Replier;

/********************************************************************
 * This function creates a new Replier type
 * 
 * Outputs:
 *  - Replier
 ********************************************************************/
Replier _new_replier();

/********************************************************************
 * This function destroys a Replier type
 * 
 * Inputs:
 *  - Replier
 ********************************************************************/
void _destroy_replier(Replier *replier);

/********************************************************************
 * This function replies a message
 * 
 * Inputs:
 *  - Replier
 *  - Message
 ********************************************************************/
void _reply(Replier replier, Message message);

#endif