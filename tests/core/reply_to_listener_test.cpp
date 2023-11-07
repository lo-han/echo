#include <gtest/gtest.h>

extern "C"
{
#include <listener.h>
#include <test_mock.h>
#include <string.h>
}


TEST(StartListening, successful_reply_chain)
{
    Listener listener = NewTestMockListener();

    ASSERT_EQ((listener != NULL), true);

    StartListening(listener);

    _test_result returnedMessage = get_test_result();
    ASSERT_EQ((strcmp(returnedMessage, "TEST_MOCK_MESSAGE235#@$v3\0") == 0), true);

    DestroyListener(&listener);
    ASSERT_EQ((listener == NULL), true);
}
