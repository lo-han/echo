#ifndef __TEST_MOCK_H__
#define __TEST_MOCK_H__

#include "listener.h"

#define DEFAULT_TEST_STRING_SIZE 32

#define NewTestMockListener() NewListener(&TestMockStartReceiving, &TestMockFlush)
#define StartTestMockListening(listener) StartListening(listener, "TEST_MOCK_MESSAGE235#@$v3\0")

typedef char *_test_result;

_test_result get_test_result();

/********************************************************************
 * This function flushes a message to an output
 *
 * Inputs:
 *  - Message
 ********************************************************************/
void TestMockFlush(Message message);

/********************************************************************
 * This function receives a message and forwards to Listener
 *
 * Inputs:
 *  - Listener
 ********************************************************************/
Bool TestMockStartReceiving(Listener listener);

#endif