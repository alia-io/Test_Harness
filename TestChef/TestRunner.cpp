#include "TestRunner.h"
#include <iostream>
#include <Windows.h>
#include <exception>
#include "TestTimer.h"
#include "TestExceptionHandler.h"

//#define TEST_RUNNER_TEST

TestRunner::TestRunner(std::string name, bool (*funcPtr)()) : testFunctionName{name}, testFunction{funcPtr} { }

bool TestRunner::runTest(TestLogger logger) {
	TestTimer timer {};
	bool result = false;
	timer.startTimer();
	try {
		result = testFunction();
	} catch (std::exception& e) {
		timer.endTimer();
		testResult = TEST_RESULT::EXCEPTION;
		std::string message = testFunctionName + ": exception raised.";
		TestExceptionHandler handler {};
		// message += " " + handler.getCustomizedString(e, LOGLEVEL::detail, timer);
		logger.writeLogInfoToFile(message, timer);
		return false;
	}

	timer.endTimer();
	if (result) {
		testResult = TEST_RESULT::PASS;
		logger.writeLogInfoToFile(std::string(testFunctionName + ": tests passed."), timer);
		return true;
	}

	testResult = TEST_RESULT::FAIL;
	logger.writeLogInfoToFile(std::string(testFunctionName + ": tests failed."), timer);
	return false;
}

#ifdef TEST_RUNNER_TEST

bool testFunc1() { return false; }
bool testFunc2() { return true; }

bool testFunc3() {
	int zero = 0;
	int divByZero = 3 / zero;
	return true;
}

int main() {
	
	bool (*test1)() = *testFunc1;
	TestLogger logger1 {};
	TestRunner runner1 {"testFunc1", test1};
	bool result1 = runner1.runTest(logger1);
	std::cout << "result1: " << result1 << std::endl;

	std::cout << "\n";

	TestLogger logger2 {};
	TestRunner runner2 {"testFunc2", *testFunc2};
	bool result2 = runner2.runTest(logger2);
	std::cout << "result2: " << result2 << std::endl;

	/*TestLogger logger3{};
	TestRunner runner3 {"testFunc3", *testFunc3};
	bool result3 = runner3.runTest(logger3);
	std::cout << "result3 = " << result3 << std::endl;*/

}
#endif