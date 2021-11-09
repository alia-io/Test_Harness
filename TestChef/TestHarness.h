#pragma once
#include <string>
#include <list>
#include <functional>
#include "TestLogger.h"
using std::string;
using std::list;
//////////////////////////////////////////////////////
// TestHarness.h								//
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
	string suiteName;
	list< bool (*)()> testList;
	TestChef::TestLogger logger;
	list<std::function<bool()>> testNewList;
public:
	void addTests(bool (*funcPtr)());
	void executor();
	TestHarness();
	TestHarness(string name,TestChef::LOGLEVEL log);
};

