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
#include "MemoryAllocatorTestDriverException1.cpp"
#include "MemoryAllocatorTestDriverException2.cpp"
#include "ContainerConversionsTestDriverException.cpp"
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

bool testMemoryAllocatorTestDriverExceptionScenario1() {
	// expect EXCEPTION
	MemoryAllocatorTestDriverException1 allocator{};
	return allocator.TEST();
}

bool testMemoryAllocatorTestDriverExceptionScenario2() {
	// expect EXCEPTION
	MemoryAllocatorTestDriverException2 allocator{};
	return allocator.TEST();
}

bool testContainerConversionsTestDriverExceptionScenario() {
	// expect EXCEPTION
	ContainerConversionsTestDriverException converter{};
	return converter.TEST();
}

bool testLengthError() {
	// expect EXCEPTION
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
	testHarness.addTests("MemoryAllocatorTestDriverExceptionScenario1", *testMemoryAllocatorTestDriverExceptionScenario1);
	testHarness.addTests("MemoryAllocatorTestDriverExceptionScenario2", *testMemoryAllocatorTestDriverExceptionScenario2);
	testHarness.addTests("ContainerConversionsTestDriverExceptionScenario", *testContainerConversionsTestDriverExceptionScenario);
	testHarness.executor();
}