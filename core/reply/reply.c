#include "reply.h"
#include "safe_memory.h"
#include "protocol.h"

#include <stdlib.h>

struct _replier{};

Replier _new_replier()
{
    Replier replier = NULL;
    safe_malloc((void **) &replier, sizeof(struct _replier));

    return replier;
}

void _destroy_replier(Replier *replier)
{
    safe_free_alloc((void **) replier, sizeof(struct _replier));
}

void _reply(Replier replier, Message message)
{
    Flush(message);
}
