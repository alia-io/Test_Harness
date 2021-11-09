#include "TestHarness.h"
#include "TestRunner.h"
#include <string>
#include <list>
using std::list;
using std::string;

//default constructor
TestHarness::TestHarness() :suiteName("Default") {}

TestHarness::TestHarness(string name):suiteName(name){
	if (name.empty())
	{
		suiteName = "Default";
	}
}


void TestHarness::addTests(bool (*func) ()) {
	testList.push_back(func);
}

void TestHarness::runAllTests() {

	for (auto const& i : testList) {
		TestLogger logger1{};
		TestRunner runner("Default", i);
		runner.runTest(logger1);
	}
	
}

