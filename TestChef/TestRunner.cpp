#include "TestRunner.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <chrono>
using std::chrono::time_point;
using std::chrono::system_clock;

//#define TEST_RUNNER_TEST

TestRunner::TestRunner(std::string name, bool (*funcPtr)()) : testFunctionName{name}, testFunction{funcPtr} { }

bool TestRunner::runTest(TestLogger logger) {
	TestTimer timer {};
	timer.startTimer();
	try {
		bool result = testFunction();
		timer.endTimer();
		if (result) {
			testResult = TEST_RESULT::PASS;
			logger.writeLogInfoToFile(std::string(testFunctionName + ": tests passed."), timer);
			return true;
		} else {
			testResult = TEST_RESULT::FAIL;
			logger.writeLogInfoToFile(std::string(testFunctionName + ": tests failed."), timer);
		}
	} catch (std::exception& e) {
		// TODO: get current time for logging
		timer.endTimer();
		testResult = TEST_RESULT::EXCEPTION;
		std::string message = testFunctionName + ": exception raised.";
		// TODO: only get exception message if log level == debug or detail
		//switch (logger.getLogLevel()) {
			//case LOGLEVEL::debug:
			//case LOGLEVEL::detail:
				//TestExceptionHandler handler{};
				// TODO: pass e to TestExceptionHandler
				//		 message += "Exception message: " + result of TestExceptionHandler
		//}
		logger.writeLogInfoToFile(message, timer);
	}
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