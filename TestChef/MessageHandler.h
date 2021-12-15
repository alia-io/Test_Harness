#pragma once
#include "BlockingQueue.h"
#include "Message.h"
#include "ResultFormatter.h"
#include "Server.h"
#include <thread>

//////////////////////////////////////////////////////
// MessageHandler.h									//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
*
* This class takes message objects and either enqueues the message contents into
* a queue for the Test Requests or the Test Results. This class also contains methods for
* dequeing messages from those created queues.
*
*/
class MessageHandler {
private:
	BlockingQueue<Message> testRequests{};
	BlockingQueue<Message> testResults{};
public:
	void enqueueTestRequests(Message requestMessage);		//enqueue message into testRequests queue
	void enqueueTestResult(Message resultMessage, TEST_RESULT result, std::string text);	//enqueue message into testResults queue
	Message dequeueTestRequest();
	Message dequeueTestResult();
};