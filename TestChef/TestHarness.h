#pragma once
#include <string>
#include <list>
#include <functional>
#include "TestLogger.h"
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
struct TestItem {
	string name;
	bool (*ptr)();
};

class TestHarness
{
private:
	string suiteName;
	list<TestItem> testList{};
	TestChef::TestLogger logger{};
	TestResultCounter counter{};
public:
	void addTests(std::string funcName, bool (*funcPtr)());
	void executor();
	void childExecutor();
	TestHarness();
	TestHarness(string name,TestChef::LOGLEVEL log);
};

