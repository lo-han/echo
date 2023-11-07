#include "test_mock.h"
#include "listener.h"
#include "test_mock.h"

#include <string.h>

#define DEFAULT_TEST_STRING_SIZE 32

char _test_message[DEFAULT_TEST_STRING_SIZE + 1];

Message TestMockStartReceiving()
{
    return "TEST_MOCK_MESSAGE235#@$v3\0";
}

void TestMockFlush(Message message)
{
    memset(_test_message, 0x00, DEFAULT_TEST_STRING_SIZE);
    strncpy(_test_message, message, DEFAULT_TEST_STRING_SIZE);
}

_test_result get_test_result()
{
    return _test_message;
}
