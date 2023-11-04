#include "trigger.h"
#include "safe_memory.h"

#include <stdlib.h>

struct _trigger
{
    Replier replier;
};

Trigger NewTrigger()
{
    Trigger trigger = NULL;
    Safe_mem_err err = safe_malloc((void **)&trigger, sizeof(struct _trigger));

    if (err == _err_no_error)
    {
        Replier replier = NewReplier();

        if (replier == NULL)
        {
            return _err_error;
        }

        trigger->replier = replier;
    }

    return trigger;
}

void DestroyTrigger(Trigger *trigger)
{
    if (trigger != NULL)
    {
        Trigger cnt_trigger = *trigger;
        _destroy_replier(&cnt_trigger->replier);

        safe_free_alloc((void **)trigger, sizeof(struct _trigger));
    }
}

void Received(Trigger trigger, Message message)
{
    if (trigger != NULL)
    {
        _reply(trigger->replier, message);
    }
}
