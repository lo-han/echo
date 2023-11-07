#ifndef __LISTENER_H__
#define __LISTENER_H__

typedef char *Message;

typedef struct _listener *Listener;

typedef void (*FlushCallback)(Message message);

typedef enum _b
{
    _false = 0,
    _true
} Bool;

typedef Bool (*StartReceiving)(Listener listener);

/********************************************************************
 * This function creates a new Listener type
 *
 * Outputs:
 *  - Listener
 ********************************************************************/
Listener NewListener(StartReceiving receiver, FlushCallback callback);

/********************************************************************
 * This function waits for a incoming message and reply a message
 *
 * Inputs:
 *  - Listener
 ********************************************************************/
void StartListening(Listener listener, Message replyMessage);

/********************************************************************
 * This function destroys a Listener type
 *
 * Inputs:
 *  - Listener
 ********************************************************************/
void DestroyListener(Listener *listener);

#endif