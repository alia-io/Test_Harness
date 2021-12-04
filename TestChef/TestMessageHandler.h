#pragma once
///////////////////////////////////////////////////////////////
//TestMessageHandler.h - Class that implements the blocking  //
//queues											         //
//Santhosh Srinivasan, Jiawen Zhen, Alifa Stith              //
//														     //
///////////////////////////////////////////////////////////////

#include "TestMessageParser.h"
#include "TestMessage.h"
#include "TestBlockingQueue.h"
#include "TestItem.h"

using namespace TestChef;
using namespace std;

class TestMessageHandler {
private:
	TestBlockingQueue<TestItem> testRequests{};
	TestBlockingQueue<TestMessage> testResults{};
public:

	void enqueueTestRequest(TestItem item);
	void enqueueTestResult(std::thread::id parentThreadId, std::thread::id childThreadId,
		TEST_RESULT result, std::string author, std::string body);
	TestItem dequeueTestRequest();
	TestMessage dequeueTestResult();
};