#pragma once
#include <string>
#include <list>
#include <functional>
#include "TestLogger.h"
#include "TestItem.h"
#include "TestMessageHandler.h"
using std::string;
using std::list;
//////////////////////////////////////////////////////
// TestHarness.h									//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* This file contains TestHarness class
* Purpose of class is to repeatedly call the testrunner class which inturn invokes the testable function
*
*/

class TestHarness
{
private:
	std::string suiteName;
	std::thread::id testHarnessThreadId;
	TestSuite::TestLogger logger{};
	TestResultCounter counter{};
	TestMessageHandler handler{};
	void executeChild();
public:
	TestHarness();
	TestHarness(std::string name, TestSuite::LOGLEVEL log);
	void execute(std::list<TestItem> tests);
};
