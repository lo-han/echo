#include "listener.h"

#include <stdlib.h>
#include <pthread.h>

struct _listener
{
    FlushCallback callback;
    StartReceiving receiver;
    pthread_t thread;
};

Listener NewListener(StartReceiving receiver, FlushCallback callback)
{
    Listener listener = NULL;
    Safe_mem_err err = safe_malloc((void **)&listener, sizeof(struct _listener));

    if (err == _err_no_error)
    {
        listener->callback = callback;
        listener->receiver = receiver;
        listener->thread = -1;
    }

    return listener;
}

void DestroyListener(Listener *listener)
{
    if (listener != NULL)
    {
        Listener ctn_listener = *listener;

        if (ctn_listener->thread != -1)
        {
            pthread_cancel(ctn_listener->thread);
        }
        safe_free_alloc((void **)listener, sizeof(struct _listener));
    }
}

void _listen_and_reply(Listener listener, Message replyMessage)
{
    while (1)
    {
        listener->receiver(listener);
        listener->callback(replyMessage);
    }
}

void StartListening(Listener listener, Message replyMessage)
{
    if (listener != NULL)
    {
        pthread_create(&listener->thread, NULL, (void *(*)(void *))_listen_and_reply, listener);
        pthread_detach(listener->thread);
    }
}
