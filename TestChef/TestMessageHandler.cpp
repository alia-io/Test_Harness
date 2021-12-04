#include "TestMessageHandler.h"

// for enqueueTestResult: the message body should be formatted in JSON as follows:
// { "result": "pass/fail/exception", "message": "[msg_string]" }
// [msg_string] is the original "body" that is passed as an argument

void TestMessageHandler::enqueueTestRequest(TestItem item)
{
}

void TestMessageHandler::enqueueTestResult(std::thread::id parentThreadId, TEST_RESULT result, std::string body)
{
}
