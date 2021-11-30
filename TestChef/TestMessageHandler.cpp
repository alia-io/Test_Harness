#include "TestMessageHandler.h"

void TestMessageHandler::initiateQueues() {
	queue<int> readyMessageQueue;
	queue<int> testRequestMessageQueue;
	queue<int> testRequestListMessageQueue;

	startQueue(readyMessageQueue);
	startQueue(testRequestMessageQueue);
	startQueue(testRequestListMessageQueue);
}

void TestMessageHandler::startQueue(std::queue<int> q)
{
	
}


void TestMessageHandler::addMessageForParent()
{
}
