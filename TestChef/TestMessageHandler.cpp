#include "TestMessageHandler.h"

// for enqueueTestResult: the message body should be formatted in JSON as follows:
// { "result": "pass/fail/exception", "message": "[msg_string]" }
// [msg_string] is the original "body" that is passed as an argument

void TestMessageHandler::addMessagetoQueue()
{	
	auto type = getMessageType();		//obtain the message type
	std::string msg = getMessage();		//obtain the message contents

	if (type == MESSAGE_TYPE::request) {		//The message is a request type
		testRequestMessageQueue.push(msg);		//Add the message to the back of the testRequestMessageQueue
	}

	if (type == MESSAGE_TYPE::request_list) {
		testRequestListMessageQueue.push(msg);			//add the DLL request to the testRequestListMessageQueue
	}
}

void TestMessageHandler::releaseMessageFromQueue()
{
	auto type = getMessageType();		//obtain the message type
	std::string msg = getMessage();		//obtain the message contents

	if (type == MESSAGE_TYPE::response) {	//The message type is a response
		testRequestMessageQueue.pop();		//Remove the message from queue now that response has been recieved
	}

	if (type == MESSAGE_TYPE::response_list) {			//message type is a response list
		cout << testRequestListMessageQueue.front();	//Remove the DLL list message from queue now that response has been recieved
	}
}

int TestMessageHandler::queueSize(queue<string> qu){ return qu.size();}

string TestMessageHandler::getFrontQueue(queue<string> qu) { return qu.front();}

string TestMessageHandler::getBackQueue(queue<string> qu) { return qu.back();}

