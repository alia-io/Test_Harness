#include "TestMessageHandler.h"

void TestMessageHandler::enqueueTestRequest(TestItem item)
{
	testRequests.enQ(item);
}

void TestMessageHandler::enqueueTestResult(std::thread::id parentThreadId,
	TEST_RESULT result, std::string body)
{
	if (result == TEST_RESULT::pass)
		body = "{ \"result\": \"pass\", \"message\": \"" + body + "\" }";
	else if (result == TEST_RESULT::fail)
		body = "{ \"result\": \"fail\", \"message\": \"" + body + "\" }";
	else if (result == TEST_RESULT::exception)
		body = "{ \"result\": \"exception\", \"message\": \"" + body + "\" }";
	else return;

	TestMessage msgObj(TestChef::THREAD_TYPE::parent, parentThreadId, TestChef::THREAD_TYPE::child, 
		this_thread::get_id(), TestChef::MESSAGE_TYPE::request, "TestHarness", body);
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
