#include "trigger.h"
#include "reply.h"

#include "protocol.h"
#include "safe_memory.h"

#include <stdlib.h>

int main()
{
    Trigger trigger = NewTrigger();

    if (trigger == NULL)
    {
        return _err_error;
    }

    StartReceiving(trigger);

    DestroyTrigger(&trigger);
}