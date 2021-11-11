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
// TestHarness.cpp									//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Implementation of Test Harness Class
* 
* Purpose of class is to repeatedly call the testrunner class which inturn invokes the testable function
*
*/

TestResultCounter counter;
//default constructor
TestHarness::TestHarness() :suiteName("Default") {}

TestHarness::TestHarness(string name, LOGLEVEL log) : suiteName(name) {
	logger.setLogLevel(log);	//calls the function for setting the log level
}

//Add callable objects to invoke
void TestHarness::addTests(std::string name, bool (*func) ()) {
	TestItem test{ name, func };
	testList.push_back(test);		//Adds items to the test list
}


void TestHarness::executor() {
	TestTimer timer{};
	counter.setTotalTests(testList.size());	//counter struct for # of pass, fail, and total tests
	timer.startTimer();						// Initiate start time
	for (auto const& test : testList) {
		TestRunner runner(test.name, test.ptr); // run each test on test list and increase the correct count
		bool outcome = runner.runTest(logger);
		if (outcome) {
			counter.incrementTestPassed();	
		}
		else {
			counter.incrementTestFailed();
		}
		
	}

	timer.endTimer();	// Submit end time to determine how much time the test list took to run
	logger.writeTestRunSummary(counter,timer);
	
}

