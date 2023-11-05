#include "mock_protocol.h"
#include "listener.h"

#include <stdio.h>

Bool MockStartReceiving(Listener listener)
{
    // Message receivedMessage = "HELLO WORLD\0";
    return _true;
}

void MockFlush(Message message)
{
    printf("%s\n", message);
}