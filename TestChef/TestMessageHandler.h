#pragma once
///////////////////////////////////////////////////////////////
//TestMessageHandler.h - Class that implements the blocking  //
//queues											         //
//Santhosh Srinivasan, Jiawen Zhen, Alifa Stith              //
//														     //
///////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <queue>
#include "TestMessage.h"

using namespace TestChef;
using namespace std;

class TestMessageHandler:TestMessage {
private:
	queue<string> readyMessageQueue;
	queue<string> testRequestMessageQueue;
	queue<string> testRequestListMessageQueue;

public:
	void addMessagetoQueue();					//Add a msg to queue based on type
	void releaseMessageFromQueue();				//Release a msg from queue based on type
	int queueSize(queue<string> qu);			//Obtain size of queue
	string getFrontQueue(queue<string> qu);	//Obtain from front of message queue
	string getBackQueue(queue<string> qu);
};