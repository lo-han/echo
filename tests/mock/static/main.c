#include "listener.h"

#include "mock_protocol.h"

#include <stdlib.h>
#include <unistd.h>

int main()
{
    Listener listener = NewMockListener();

    if (listener == NULL)
    {
        return -1;
    }

    StartListening(listener);

    DestroyListener(&listener);
}