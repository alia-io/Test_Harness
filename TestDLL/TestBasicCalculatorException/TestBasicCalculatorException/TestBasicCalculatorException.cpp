// TestBasicCalculatorException.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "TestBasicCalculatorException.h"

#include <string>
#include <stdexcept>


// This is an example of an exported variable
TESTBASICCALCULATOREXCEPTION_API int nTestBasicCalculatorException=0;

// This is an example of an exported function.
TESTBASICCALCULATOREXCEPTION_API int fnTestBasicCalculatorException(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTestBasicCalculatorException::CTestBasicCalculatorException()
{
    return;
}

int divide(int operand1, int operand2) {
	if (operand2 == 0) {
		throw std::runtime_error("Math error: Attempted to divide by Zero.");
	}
	return operand1 / operand2;
}

extern "C" TESTBASICCALCULATOREXCEPTION_API bool TEST() {
	bool outcome = false;
	if (divide(12, 0) == 6) {
		outcome = true;
	}
	return outcome;
}
