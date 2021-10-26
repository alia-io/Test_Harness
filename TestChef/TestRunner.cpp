#include "TestRunner.h"
#include <iostream>

TestRunner::TestRunner(std::string name, bool (*funcPtr)())
	: testFunctionName{name}, testFunction {funcPtr} { }

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

std::string TestRunner::getTestFunctionName() { return testFunctionName; }

bool TestRunner::getTestResult() { return testResult; }

std::string TestRunner::getExceptionMsg() { return exceptionMsg; }

double TestRunner::getTimeTaken() { return timer.timeTaken(); }