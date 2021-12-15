#include "TestResultCounter.h"

//////////////////////////////////////////////////////
// TestResultCounter.cpp							//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* This is the implementation of class TestResultCounter
* This class is to record the count for the amount of passed, failed, and total tests.
*
*/

void TestResultCounter::setTotalTests(int count) { totalTests = count; };	// set the total test amount
void TestResultCounter::incrementTestPassed() { testsPassed++; };		// increment tests passed
void TestResultCounter::incrementTestFailed() { testsFailed++; };		// increment tests failed 

int TestResultCounter::getTestsPassed() { return testsPassed; };	// return counter variables
int TestResultCounter::getTestsFailed() { return testsFailed; };
int TestResultCounter::getTestsTotal() { return totalTests; }

std::string TestResultCounter::testResultSummary() {
	std::string out = " Total Tests           " + std::to_string(totalTests);
	out += "\n                        Tests Passed          " + std::to_string(testsPassed);
	out += "\n                        Tests Failed          " + std::to_string(testsFailed);
	//out += "\n                        Total Time Taken      " + Timer::convertTimeToString(timer->timeTakenSeconds()) + " seconds";
	return out;
}

void TestResultCounter::setTimer(Timer* t) { timer = t; }
Timer* TestResultCounter::getTimer() { return timer; }