#pragma once
#include <exception>
#include <string>
#include "TestTimer.h"
#include "TestExceptionHandler.h"

class TestRunner {
private:
	TestTimer timer {};
	TestExceptionHandler exceptionHandler {};
	std::string testFunctionName;
	bool (*testFunction)();
	bool testResult = false;
	std::string exceptionMsg = "";
public:
	TestRunner(std::string name, bool (*funcPtr)());
	bool runTest();
	bool getTestResult();
	std::string getExceptionMsg();
	double getTimeTaken();
};