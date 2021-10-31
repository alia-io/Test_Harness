// TestChef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BasicCalculator.h"
#include "TestLogger.h"
#include "TestRunner.h"
using std::cout;
using std::endl;
bool testFunc1() { return false; }
bool testFunc2() { return true; }

bool testFunc3() {
	int zero = 0;
	int divByZero = 3 / zero;
	return true;
}

int main() {

	bool (*test1)() = *testFunc1;
	TestLogger logger1{};
	TestRunner runner1{ "testFunc1", test1 };
	bool result1 = runner1.runTest(logger1);
	std::cout << "result1: " << result1 << std::endl;

	std::cout << "\n";

	TestLogger logger2{};
	TestRunner runner2{ "testFunc2", *testFunc2 };
	bool result2 = runner2.runTest(logger2);
	std::cout << "result2: " << result2 << std::endl;

	/*TestLogger logger3{};
	TestRunner runner3 {"testFunc3", *testFunc3};
	bool result3 = runner3.runTest(logger3);
	std::cout << "result3 = " << result3 << std::endl;*/

}