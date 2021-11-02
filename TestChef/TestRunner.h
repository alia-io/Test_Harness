#pragma once
#include <string>
#include "TestLogger.h"
using namespace TestChef;

class TestRunner {
private:
	std::string testFunctionName;
	bool (*testFunction)();
public:
	TestRunner(std::string name, bool (*funcPtr)());
	bool runTest(TestLogger logger);
};