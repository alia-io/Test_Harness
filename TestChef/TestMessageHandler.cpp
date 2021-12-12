#include "TestMessageHandler.h"

void TestMessageHandler::enqueueTestRequest(TestItem item) { testRequests.enQ(item); }

void TestMessageHandler::enqueueTestResult(std::thread::id parentThreadId, TEST_RESULT result, std::string messageText) {
	TestMessage message{ THREAD_TYPE::child, std::this_thread::get_id(), THREAD_TYPE::parent, parentThreadId,
		MESSAGE_TYPE::result, "TestHarness", TestMessageParser::convertTestResultToJSONBody(result, messageText) };
	testResults.enQ(message);
}

TestItem TestMessageHandler::dequeueTestRequest() { return testRequests.deQ(); }
TestMessage TestMessageHandler::dequeueTestResult() { return testResults.deQ(); }