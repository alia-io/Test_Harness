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
class TestHarness
{
private:
	struct TestItem {
		string name;
		bool (*ptr)();
	};
	string suiteName;
	list<TestItem> testList;
	TestChef::TestLogger logger;
	list<TestItem> testNewList;
public:
	void addTests(std::string funcName, bool (*funcPtr)());
	void executor();
	TestHarness();
	TestHarness(string name,TestChef::LOGLEVEL log);
};

