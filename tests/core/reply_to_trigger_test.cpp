#include <gtest/gtest.h>

extern "C"
{
#include <trigger.h>
#include <reply.h>
#include <protocol.h>
#include <test_mock.h>
#include <string.h>
}


TEST(Received, successful_reply_chain)
{
    Replier replier = NewReplier();

    ASSERT_EQ((replier != NULL), true);

    Trigger trigger = NewTrigger(replier);

    ASSERT_EQ((trigger != NULL), true);

    Bool received = StartReceiving(trigger);
    ASSERT_EQ((received == _true), true);

    _test_result returnedMessage = get_test_result();
    ASSERT_EQ((strcmp(returnedMessage, "TEST_MOCK_MESSAGE235#@$v3\0") == 0), true);

    DestroyTrigger(&trigger);
    ASSERT_EQ((trigger == NULL), true);

    DestroyReplier(&replier);
    ASSERT_EQ((replier == NULL), true);
}
