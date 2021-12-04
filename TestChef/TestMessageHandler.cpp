#include "TestMessageHandler.h"

// for enqueueTestResult: the message body should be formatted in JSON as follows:
// { "result": "pass/fail/exception", "message": "[msg_string]" }
// [msg_string] is the original "body" that is passed as an argument

void TestMessageHandler::enqueueTestRequest(TestItem item)
{
	testRequests.enQ(item);
}

void TestMessageHandler::enqueueTestResult(std::thread::id parentThreadId, std::thread::id childThreadId,
	TEST_RESULT result, std::string author, std::string body)
{
    body = R"( { "result": "pass/fail/exception", "message": "[body]" })";
	TestMessage msgObj(TestChef::THREAD_TYPE::parent, parentThreadId, TestChef::THREAD_TYPE::child, 
		childThreadId, TestChef::MESSAGE_TYPE::request, author, body);
	testResults.enQ(msgObj);
}

TestItem TestMessageHandler::dequeueTestRequest()
{
	return testRequests.deQ();
}

TestMessage TestMessageHandler::dequeueTestResult()
{	
	return testResults.deQ();
}
