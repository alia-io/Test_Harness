#pragma once
///////////////////////////////////////////////////////////////
//TestMessageHandler.h - Class that implements the blocking  //
//queues											         //
//Santhosh Srinivasan, Jiawen Zhen, Alifa Stith              //
//														     //
///////////////////////////////////////////////////////////////

#include "TestRunner.h"
#include "TestMessage.h"
#include "TestBlockingQueue.h"
#include "TestItem.h"

using namespace TestChef;
using namespace std;

class TestMessageHandler {
private:
	//queue<string> readyMessageQueue;
	//queue<string> testRequestMessageQueue;
	//queue<string> testRequestListMessageQueue;
	TestBlockingQueue<TestItem> testRequests{};
	TestBlockingQueue<TestMessage> testResults{};
public:
	//void addMessagetoQueue();					//Add a msg to queue based on type
	//void releaseMessageFromQueue();				//Release a msg from queue based on type
	//int queueSize(queue<string> qu);			//Obtain size of queue
	//string getFrontQueue(queue<string> qu);	//Obtain from front of message queue
	//string getBackQueue(queue<string> qu);
	void enqueueTestRequest(TestItem item);
	void enqueueTestResult(std::thread::id parentThreadId, TEST_RESULT result, std::string body);
};