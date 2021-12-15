#include "TestRunner.h"
#include "TestDLLLoader.h"

//////////////////////////////////////////////////////
// TestRunner.cpp									//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* This file contains the implementation of the TestRunner class.
*
* This class is used to run each individual test, obtain the result, and pass logging information
* to the logger.
*
* Public Interface:
* -----------------
* TestRunner	initialize TestRunner object with the name of the test function and a pointer to the test function
* runTest		pass TestLogger object to run the test function
*
*/

using namespace TestMessenger;

TestRunner::TestRunner(Message msg) : message{ msg } {
	testName = msg.getResultMessageBody().testName;
}

void TestRunner::runTest(MessageHandler* messageHandler, LOG_LEVEL logLevel) {
	Timer timer{};
	bool result = false;
	timer.startTimer();
	TestDLLLoader loader;
	
	try {
		result = loader.dllLoader(testName + ".dll"); //function name is expected of format XXXXX.dll
	}
	catch (std::exception& e) {
		timer.endTimer();
		messageHandler->enqueueTestResult(message, TEST_RESULT::exception,
			ResultFormatter::testExceptionMessage(testName, e, logLevel));
		return;
	}

	timer.endTimer();

	if (result) {
		messageHandler->enqueueTestResult(message, TEST_RESULT::pass,
			ResultFormatter::testPassedMessage(testName, timer));
		return;
	}

	messageHandler->enqueueTestResult(message, TEST_RESULT::fail,
		ResultFormatter::testFailedMessage(testName, timer));
}