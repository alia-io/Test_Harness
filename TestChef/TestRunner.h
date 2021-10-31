#pragma once
#include <exception>
#include <string>
#include "TestTimer.h"
#include "TestExceptionHandler.h"
#include "TestLogger.h"
using namespace TestChef;

enum class TEST_RESULT { NONE, PASS, FAIL, EXCEPTION };

class TestRunner {
private:
	std::string testFunctionName;
	bool (*testFunction)();
	TEST_RESULT testResult = TEST_RESULT::NONE;
public:
	TestRunner(std::string name, bool (*funcPtr)());
	bool runTest(TestLogger logger);
};