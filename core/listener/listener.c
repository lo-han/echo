#include "listener.h"
#include "safe_memory.h"

#include <stdlib.h>

struct _listener
{
    FlushCallback callback;
    StartReceiving receiver;
};

Listener NewListener(StartReceiving receiver, FlushCallback callback)
{
    Listener listener = NULL;
    Safe_mem_err err = safe_malloc((void **)&listener, sizeof(struct _listener));

    if (err == _err_no_error)
    {
        listener->callback = callback;
        listener->receiver = receiver;
    }

    return listener;
}

void DestroyListener(Listener *listener)
{
    if (listener != NULL)
    {
        Listener ctn_listener = *listener;

        safe_free_alloc((void **)listener, sizeof(struct _listener));
    }
}

void StartListening(Listener listener, Message replyMessage)
{
    if (listener != NULL)
    {
        if (listener->receiver(listener) == _true)
        {
            listener->callback(replyMessage);
        }
    }
}
