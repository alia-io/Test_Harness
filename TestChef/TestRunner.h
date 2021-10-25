#pragma once
#include "TestTimer.h"
#include "TestExceptionHandler.h"

class TestRunner {
private:
	TestTimer timer;
	TestExceptionHandler exceptionHandler;
public:
	bool runTest(void (*funcPtr)());
};

