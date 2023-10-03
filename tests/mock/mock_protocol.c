#include "protocol.h"
#include "trigger.h"

#include <stdio.h>

Bool StartReceiving(Trigger trigger)
{
    Message message = "HELLO WORLD\0";

    Received(trigger, message);
    return _true;
}

void Flush(Message message)
{
    printf("%s\n", message);
}