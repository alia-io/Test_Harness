#include "TestRunner.h"
#include <iostream>

TestRunner::TestRunner(bool (*funcPtr)()) : testFunction{funcPtr} { }

bool TestRunner::runTest() {
	timer.startTimer();
	try {
		testResult = testFunction();
	}
	catch (std::exception& e) {
		// TODO: pass e to TestExceptionHandler
		//		 set exceptionMsg to result
	}
	timer.endTimer();
	return testResult;
}

bool TestRunner::getTestResult() { return testResult; }

std::string TestRunner::getExceptionMsg() { return exceptionMsg; }

double TestRunner::getTimeTaken() { return timer.timeTaken(); }