// TestChef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BasicCalculator.h"
#include "AdvCalculator.h"
#include "TestLogger.h"
#include "TestRunner.h"
#include "TestHarness.h"
#include "BasicCalculator.h"
#include <vector>
#include <functional>
#include "BasicCalculatorTestDriver.cpp"
#include "BasicCalculatorTestDriverFail.cpp"
#include "BasicCalculatorTestDriverException.cpp"
#include "AdvCalculatorTestDriver.cpp"
#include "MemoryAllocatorTestDriverException.cpp"
using namespace TestChef;
using std::cout;
using std::endl;

bool testBasicCalculatorPassScenario() {
	// expect PASS
	BasicCalculatorTestDriver calc{};
	return calc.TEST();
}

bool testBasicCalculatorFailScenario() {
	// expect FAIL
	BasicCalculatorTestDriverFail calc{};
	return calc.TEST();
}

bool testBasicCalculatorTestDriverExceptionScenario() {
	// expect EXCEPTION
	BasicCalculatorTestDriverException calc{};
	return calc.TEST();
}

bool testAdvCalculatorTestDriverPassScenario() {
	// expect PASS
	AdvCalculatorTestDriver calc{};
	return calc.TEST();
}

bool testMemoryAllocatorTestDriverExceptionScenario() {
	MemoryAllocatorTestDriverException allocator{};
	return allocator.TEST();
}

bool testLengthError() {
	std::vector<int> myvector;
	myvector.resize(myvector.max_size() + 1);

	return true;
}


int main() {
	
	TestHarness testHarness("def",LOGLEVEL::debug);
	testHarness.addTests("testLengthError", * testLengthError);
	testHarness.addTests("BasicCalculatorPassScenario", *testBasicCalculatorPassScenario);
	testHarness.addTests("BasicCalculatorFailScenario", *testBasicCalculatorFailScenario);
	testHarness.addTests("BasicCalculatorTestDriverExceptionScenario", *testBasicCalculatorTestDriverExceptionScenario);
	testHarness.addTests("AdvCalculatorTestDriverPassScenario", *testAdvCalculatorTestDriverPassScenario);
	testHarness.addTests("MemoryAllocatorTestDriverExceptionScenario", *testMemoryAllocatorTestDriverExceptionScenario);
	testHarness.executor();
}