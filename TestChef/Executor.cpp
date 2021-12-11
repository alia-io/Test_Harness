// Executor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestLogger.h"
#include "TestRunner.h"
#include "TestHarness.h"
#include "BasicCalculatorTestDriverPass.h"
#include "BasicCalculatorTestDriverFail.h"
#include "BasicCalculatorTestDriverException.h"
#include "AdvCalculatorTestDriverPass.h"
#include "MemoryAllocatorTestDriverException1.h"
#include "MemoryAllocatorTestDriverException2.h"
#include "ContainerConversionsTestDriverFail.h"
#include "ContainerConversionsTestDriverException.h"
#include "LengthErrorTestDriverException.h"
#include "OverflowErrorTestDriverException.h"
using namespace TestChef;
using std::cout;
using std::endl;

bool testBasicCalculatorPassScenario() {	// expect PASS
	BasicCalculatorTestDriverPass calc{};
	return calc.TEST();
}

bool testBasicCalculatorFailScenario() {	// expect FAIL
	BasicCalculatorTestDriverFail calc{};
	return calc.TEST();
}

bool testBasicCalculatorTestDriverExceptionScenario() {	// expect EXCEPTION
	BasicCalculatorTestDriverException calc{};
	return calc.TEST();
}

bool testAdvCalculatorTestDriverPassScenario() {	// expect PASS
	AdvCalculatorTestDriverPass calc{};
	return calc.TEST();
}

bool testMemoryAllocatorTestDriverExceptionScenario1() {	// expect EXCEPTION
	MemoryAllocatorTestDriverException1 allocator{};
	return allocator.TEST();
}

bool testMemoryAllocatorTestDriverExceptionScenario2() {	// expect EXCEPTION
	MemoryAllocatorTestDriverException2 allocator{};
	return allocator.TEST();
}

bool testContainerConversionsTestDriverFailScenario() {	// expect FAIL
	ContainerConversionsTestDriverFail converter{};
	return converter.TEST();
}

bool testContainerConversionsTestDriverExceptionScenario() {	// expect EXCEPTION
	ContainerConversionsTestDriverException converter{};
	return converter.TEST();
}

bool testLengthErrorTestDriverExceptionScenario() {	// expect EXCEPTION
	LengthErrorTestDriverException driver{};
	return driver.TEST();
}

bool testOverflowErrorTestDriverExceptionScenario() {	// expect EXCEPTION
	OverflowErrorTestDriverException driver{};
	return driver.TEST();
}


/*int main() {
	
	std::list<TestItem> tests{
		TestItem{"BasicCalculatorPassScenario", *testBasicCalculatorPassScenario},
		TestItem{"BasicCalculatorFailScenario", *testBasicCalculatorFailScenario},
		TestItem{"BasicCalculatorTestDriverExceptionScenario", *testBasicCalculatorTestDriverExceptionScenario},
		TestItem{"AdvCalculatorTestDriverPassScenario", *testAdvCalculatorTestDriverPassScenario},
		TestItem{"MemoryAllocatorTestDriverExceptionScenario1", *testMemoryAllocatorTestDriverExceptionScenario1},
		TestItem{"MemoryAllocatorTestDriverExceptionScenario2", *testMemoryAllocatorTestDriverExceptionScenario2},
		TestItem{"ContainerConversionsTestDriverFailScenario", *testContainerConversionsTestDriverFailScenario},
		TestItem{"ContainerConversionsTestDriverExceptionScenario", *testContainerConversionsTestDriverExceptionScenario},
		TestItem{"LengthErrorTestDriverExceptionScenario", *testLengthErrorTestDriverExceptionScenario},
		TestItem{"OverflowErrorTestDriverExceptionScenario", *testOverflowErrorTestDriverExceptionScenario}
	};

	TestHarness testHarness("def", LOGLEVEL::debug);
	testHarness.execute(tests);
}*/