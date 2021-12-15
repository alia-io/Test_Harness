#include "TestHarness.h"

//////////////////////////////////////////////////////
// TestHarness.cpp									//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Implementation of Test Harness Class
*
* Purpose of class is to repeatedly call the testrunner class which inturn invokes the testable function
*
*/

TestHarness::TestHarness(std::string name, Message request) : suiteName{ name }, requestMessage{ request } {
	StaticLogger<1>::setLogLevel(request.getRequestMessageBody().logLevel);
}

MessageHandler* TestHarness::getHandler() { return &handler; }

void TestHarness::execute() {
	parentRunner();
}

void TestHarness::parentRunner() {

	const int NUM_THREADS = 3;
	numberOfTests = requestMessage.getRequestMessageBody().testCount;

	std::vector<std::thread> threads{};		// child threads
	for (int i = 0; i < NUM_THREADS; ++i) {
		threads.push_back(std::thread([=] { childRunner(); }));
	}

	handler.enqueueTestRequests(requestMessage);	// enqueue test requests

	for (auto& thr : threads) {
		if (thr.joinable()) thr.join();
	}
}

void TestHarness::childRunner() {
	while (true) {
		if (numberOfTests <= 0) break;
		Message message = handler.dequeueTestRequest();
		TestRunner runner{ message };
		runner.runTest(&handler, StaticLogger<1>::getLogLevel());
		mtx.lock();
		numberOfTests--;
		mtx.unlock();
	}
}