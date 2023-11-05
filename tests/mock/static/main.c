#include "listener.h"

#include "mock_protocol.h"

#include <stdlib.h>

int main()
{
    Listener listener = NewMockListener();

    if (listener == NULL)
    {
        return -1;
    }

    StartMockListening(listener);

    DestroyListener(&listener);
}