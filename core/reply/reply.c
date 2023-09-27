#include "reply.h"
#include "safe_memory.h"
#include "protocol.h"

#include <stdlib.h>

struct _replier{};

Replier NewReplier()
{
    Replier replier = NULL;
    safe_malloc((void **) &replier, sizeof(struct _replier));

    return replier;
}

void DestroyReplier(Replier *replier)
{
    safe_free_alloc((void **) replier, sizeof(struct _replier));
}

void Reply(Replier replier, Message message)
{
    Flush(message);
}
