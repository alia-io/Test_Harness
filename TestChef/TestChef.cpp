// TestChef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <functional>
#include "TestLogger.h"
#include "TestRunner.h"
#include "TestHarness.h"
#include "BasicCalculator.h"
#include "BasicCalculatorTestDriver.cpp"
#include "BasicCalculatorTestDriverFail.cpp"
#include "BasicCalculatorTestDriverException.cpp"
#include "AdvCalculatorTestDriver.cpp"
#include "MemoryAllocatorTestDriverException1.cpp"
#include "MemoryAllocatorTestDriverException2.cpp"
#include "ContainerConversionsTestDriverFail.cpp"
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

bool testContainerConversionsTestDriverFailScenario() {
	// expect FAIL
	ContainerConversionsTestDriverFail converter{};
	return converter.TEST();
}

bool testContainerConversionsTestDriverExceptionScenario() {
	// expect EXCEPTION
	ContainerConversionsTestDriverException converter{};
	return converter.TEST();
}

bool testLengthError() {
	// expect EXCEPTION
	std::vector<int> vec;
	vec.resize(vec.max_size() + 1);
	return true;
}

bool testOverflowError() {
	// expect EXCEPTION
	std::bitset<100> bs;
	bs[99] = 1;
	bs[0] = 1;
	unsigned long ul = bs.to_ulong();
	return true;
}


int main() {
	
	TestHarness testHarness("def",LOGLEVEL::debug);
	testHarness.addTests("BasicCalculatorPassScenario", *testBasicCalculatorPassScenario);
	testHarness.addTests("BasicCalculatorFailScenario", *testBasicCalculatorFailScenario);
	testHarness.addTests("BasicCalculatorTestDriverExceptionScenario", *testBasicCalculatorTestDriverExceptionScenario);
	testHarness.addTests("AdvCalculatorTestDriverPassScenario", *testAdvCalculatorTestDriverPassScenario);
	testHarness.addTests("MemoryAllocatorTestDriverExceptionScenario1", *testMemoryAllocatorTestDriverExceptionScenario1);
	testHarness.addTests("MemoryAllocatorTestDriverExceptionScenario2", *testMemoryAllocatorTestDriverExceptionScenario2);
	testHarness.addTests("ContainerConversionsTestDriverFailScenario", *testContainerConversionsTestDriverFailScenario);
	testHarness.addTests("ContainerConversionsTestDriverExceptionScenario", *testContainerConversionsTestDriverExceptionScenario);
	testHarness.addTests("testLengthError", *testLengthError);
	testHarness.addTests("testOverflowError", *testOverflowError);
	testHarness.executor();
}