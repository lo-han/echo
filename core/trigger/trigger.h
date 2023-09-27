#ifndef __TRIGGER_H__
#define __TRIGGER_H__

#include "reply.h"

typedef struct _trigger *Trigger;

/********************************************************************
 * This function creates a new Trigger type
 *
 * Inputs:
 *  - Replier
 * Outputs:
 *  - Trigger
 ********************************************************************/
Trigger NewTrigger(Replier replier);

/********************************************************************
 * This function destroys a Trigger type
 *
 * Inputs:
 *  - Trigger
 ********************************************************************/
void DestroyTrigger(Trigger trigger);

/********************************************************************
 * This function waits for a incoming message and triggers a reply
 *
 * Inputs:
 *  - Trigger
 *  - Message
 ********************************************************************/
void Received(Trigger trigger, Message message);

#endif