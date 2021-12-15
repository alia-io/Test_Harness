#include "MessageHandler.h"

//////////////////////////////////////////////////////
// MessageHandler.cpp								//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
*
* This is the implementation file that takes message objects and either enqueues the message contents into
* a queue for the Test Requests or the Test Results. This class also contains methods for
* dequeing messages from those created queues.
*
*/

/* Enqueue each testList test into the testRequest queue */
void MessageHandler::enqueueTestRequests(Message requestMsg) {
	for (std::string testName : requestMsg.getRequestMessageBody().testList) {
		Message msg{ Server::ipVersion, Server::ipAddress, Server::portNumber, requestMsg.sourceIpVersion(),
			requestMsg.sourceIpAddress(), requestMsg.sourcePort(), testName };
		testRequests.enQ(msg);
	}
}

/* Enqueue each the results message after running the test into the testResults queue */
void MessageHandler::enqueueTestResult(Message requestMsg, TEST_RESULT result, std::string text) {
	Message msg{ Server::ipVersion, Server::ipAddress, Server::portNumber, requestMsg.sourceIpVersion(),
		requestMsg.sourceIpAddress(), requestMsg.sourcePort(), requestMsg.getResultMessageBody().testName };
	msg.setTestResult(result, text);
	testResults.enQ(msg);
}

Message MessageHandler::dequeueTestRequest() { return testRequests.deQ(); }
Message MessageHandler::dequeueTestResult() { return testResults.deQ(); }