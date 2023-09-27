#include "trigger.h"
#include "reply.h"

#include "protocol.h"
#include "safe_memory.h"

#include <stdlib.h>

int main()
{
    Replier replier = NewReplier();

    if (replier == NULL)
    {
        return _err_error;
    }

    Trigger trigger = NewTrigger(replier);

    if (trigger == NULL)
    {
        return _err_error;
    }

    StartReceiving(trigger);

    DestroyTrigger(&trigger);
    DestroyReplier(&replier);
}