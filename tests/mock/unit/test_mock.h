#ifndef __TEST_MOCK_H__
#define __TEST_MOCK_H__

#include "listener.h"

#define DEFAULT_TEST_STRING_SIZE 32

#define NewTestMockListener() NewListener(&TestMockStartReceiving, &TestMockFlush)

typedef char *_test_result;

_test_result get_test_result();

/********************************************************************
 * This function receives a message and forwards to Listener
 *
 * Outputs:
 *  - Message
 ********************************************************************/
Message TestMockStartReceiving();

/********************************************************************
 * This function flushes a message to an output
 *
 * Inputs:
 *  - Message
 ********************************************************************/
void TestMockFlush(Message message);

#endif