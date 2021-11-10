#include "TestHarness.h"
#include "TestRunner.h"
#include "TestLogger.h"
#include "TestTimer.h"
using namespace TestChef;
#include <iostream>
#include <string>
#include <list>
#include <functional>

using std::list;
using std::string;

//////////////////////////////////////////////////////
// TestHarness.h								//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Implementation of Test Harness Class
*
*/


std::function<bool()> func;

TestResultCounter counter;
//default constructor
TestHarness::TestHarness() :suiteName("Default") {}

TestHarness::TestHarness(string name, LOGLEVEL log) : suiteName(name) {
	logger.setLogLevel(log);
}

//Add callable objects to invoke
void TestHarness::addTests(std::string name, bool (*func) ()) {
	TestItem test{ name, func };
	testList.push_back(test);
}


void TestHarness::executor() {
	TestLogger logger;
	TestTimer timer{};
	counter.setTotalTests(testList.size());
	timer.startTimer();
	for (auto const& test : testList) {
		TestRunner runner(test.name, test.ptr);
		bool outcome = runner.runTest(logger);
		if (outcome) {
			counter.incrementTestPassed();
		}
		else {
			counter.incrementTestFailed();
		}
		
	}

	timer.endTimer();
	logger.printTestRunSummary(counter,timer);
	
}

