#include "mock_protocol.h"
#include "listener.h"

#include <stdio.h>
#include <string.h>

Message MockStartReceiving()
{
    return "HELLO WORLD\0";
}

void MockFlush(Message message)
{
    if (strcmp(message, "HELLO WORLD\0") == 0)
    {
        printf("%s\n", "HELLO!\0");
    }
}