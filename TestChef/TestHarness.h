#pragma once
#include <string>
#include <list>
using std::string;
using std::list;
//////////////////////////////////////////////////////
// TestHarness.h								//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* This file contains TestHarness class
*
*/
class TestHarness
{
private:
	string suiteName;
	list< bool (*)()> testList;
public:
	void addTests(bool (*funcPtr)());
	void runAllTests();
	TestHarness();
	TestHarness(string name);
};

