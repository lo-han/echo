#include <trigger.h>
#include <safe_memory.h>

#include <stdlib.h>

typedef struct _trigger
{
    Replier replier
};

Trigger NewTrigger(Replier replier)
{
    Trigger trigger = NULL;
    Safe_mem_err err = safe_malloc(&trigger, sizeof(struct _trigger));

    if (err == _err_no_error)
    {
        trigger->replier = replier;
    }

    return trigger;
}

void DestroyTrigger(Trigger trigger)
{
    safe_free_alloc(&trigger, sizeof(struct _trigger));
}

void Received(Trigger trigger, Message message)
{
    if (trigger != NULL)
    {
        Reply(trigger->replier, message);
    }
}
