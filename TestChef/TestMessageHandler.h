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

using namespace std;
class TestMessageHandler {
public:
	void addMessageForParent();
	void initiateQueues();
	void startQueue(std::queue<int> q);

private:

};