#include "TestMessageHandler.h"

void TestMessageHandler::enqueueTestRequest(TestItem item)
{
	testRequests.enQ(item);
}

void TestMessageHandler::enqueueTestResult(std::thread::id parentThreadId, std::thread::id childThreadId,
	TEST_RESULT result, std::string author, std::string body)
{	
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
