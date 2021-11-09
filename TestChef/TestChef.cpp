// TestChef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BasicCalculator.h"
#include "AdvCalculator.h"
#include "TestLogger.h"
#include "TestRunner.h"
#include "TestHarness.h"
#include <vector>
#include <functional>
using namespace TestChef;
using std::cout;
using std::endl;

bool testFunc1() {		// expect FAIL
	BasicCalculator calculator{};
	return calculator.add(3, 5) == 7 || calculator.multiply(10, 2) != 20;
}

bool testFunc2() {		// expect PASS
	BasicCalculator calculator{};
	return calculator.add(3, 5) == 8 && calculator.subtract(5, 3) == 2
		&& calculator.multiply(10, 2) == 20 && calculator.divide(10, 2) == 5;
}

bool testFunc3() {		// expect EXCEPTION
	// TODO: throw divide by zero exception
	BasicCalculator calculator{};
	return calculator.subtract(5, 3) > 5 || calculator.divide(4, 0) == 4;
}

bool testLengthError() {
	std::vector<int> myvector;
	myvector.resize(myvector.max_size() + 1);

	return true;
}

/*int main() {

	TestLogger logger1{};
	TestRunner runner1{ "testFunc1", *testFunc1 };
	bool result1 = runner1.runTest(logger1);
	std::cout << "result1: " << result1 << std::endl;

	TestLogger logger2{};
	TestRunner runner2{ "testFunc2", *testFunc2 };
	bool result2 = runner2.runTest(logger2);
	std::cout << "result2: " << result2 << std::endl;

	/*TestLogger logger3{};
	TestRunner runner3 {"testFunc3", *testFunc3};
	bool result3 = runner3.runTest(logger3);
	std::cout << "\nresult3 = " << result3 << std::endl;
}*/

int main() {
	
	TestHarness testHarness("def",LOGLEVEL::debug);
	testHarness.addTests(*testLengthError);
	testHarness.addTests(*testFunc1);
	testHarness.addTests(*testFunc2);
	testHarness.addTests(*testFunc3);
	testHarness.executor();
}