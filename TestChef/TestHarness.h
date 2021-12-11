#pragma once
#include "TestLogger.h"
#include "TestMessageHandler.h"
#include "TestMessageParser.h"
#include "TestRunner.h"
#include "TestLogger.h"
#include "TestTimer.h"
#include <functional>
#include <iostream>
#include <string>
#include <list>
#include <thread>
#include "TestItem.h"

using namespace TestSuite;

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
	TestHarness(std::string name, TestSuite::LOG_LEVEL log);
	void execute(std::list<TestItem> tests);
};