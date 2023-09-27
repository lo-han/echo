#include <reply.h>
#include <safe_memory.h>

#include <stdlib.h>

typedef struct _replier{};

Replier NewReplier()
{
    Replier replier = NULL;
    safe_malloc(&replier, sizeof(struct _replier));

    return replier;
}

void DestroyReplier(Replier replier)
{
    safe_free_alloc(&replier, sizeof(struct _replier));
}

void Reply(Replier replier, Message message)
{
    Flush(message);
}
