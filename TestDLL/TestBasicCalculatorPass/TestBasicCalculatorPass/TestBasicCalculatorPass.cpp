// TestBasicCalculatorPass.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "TestBasicCalculatorPass.h"


// This is an example of an exported variable
TESTBASICCALCULATORPASS_API int nTestBasicCalculatorPass=0;

// This is an example of an exported function.
TESTBASICCALCULATORPASS_API int fnTestBasicCalculatorPass(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTestBasicCalculatorPass::CTestBasicCalculatorPass()
{
    return;
}


	int add(int operand1, int operand2) {
		return operand1 + operand2;
	}

	int subtract(int operand1, int operand2) {
		return operand1 - operand2;
	}

	int multiply(int operand1, int operand2) {
		return operand1 * operand2;
	}

	int divide(int operand1, int operand2) {
		return operand1 / operand2;
	}

	bool isZero(int number) {
		bool result = false;
		if (number != 0) {
			result = true;
		}
		return result;
	}
extern "C" TESTBASICCALCULATORPASS_API bool TEST() {

	bool outcome = false;
	if (add(2, 2) == 4 && add(1, 0) == 1 && add(0, 12) == 12 &&
		subtract(2, 2) == 0 && subtract(5, 2) == 3 && subtract(0, 5) == -5 && subtract(5, 0) == 5 &&
		multiply(2, 1) == 2 && multiply(-7, 7) == -49 && multiply(0, 0) == 0 && multiply(-4, -3) == 12 &&
		divide(12, 2) == 6 && divide(3, 3) == 1 && divide(0, 4) == 0 && divide(15, 1) == 15) {
		outcome = true;
	}
	return outcome;
}