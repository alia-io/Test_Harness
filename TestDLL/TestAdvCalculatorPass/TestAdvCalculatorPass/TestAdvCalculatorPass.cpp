// TestAdvCalculatorPass.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "TestAdvCalculatorPass.h"


// This is an example of an exported variable
TESTADVCALCULATORPASS_API int nTestAdvCalculatorPass=0;

// This is an example of an exported function.
TESTADVCALCULATORPASS_API int fnTestAdvCalculatorPass(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTestAdvCalculatorPass::CTestAdvCalculatorPass()
{
    return;
}

int exp(int operand1, int operand2) {
	if (operand2 != 0) { //check if the power is non-zero
		return (operand1 * exp(operand1, operand2 - 1)); //multiply the base with itself until power is zero
	}
	else {
		return 1; //power is zero and base^0=1
	}
}

int modulo(int operand1, int operand2) {
	return operand1 % operand2;
}

int factorial(int operand1) {
	if (operand1 != 0) { //check if the power is non-zero
		return (operand1 * factorial(operand1 - 1)); //multiply the operand with operand-1 recursively
	}
	else {
		return 1; //factorial of zero = 1
	}
}

int gcd(int operand1, int operand2) {
	if (operand1 == 0) {	//return gcd of the operand that is non-zero
		return operand2;
	}
	if (operand2 == 0) {
		return operand1;
	}

	if (operand1 > operand2) {
		return gcd(operand1 - operand2, operand2); //subtract the smaller num from the larger until they are equal
	}
	else {
		return gcd(operand1, operand2 - operand1);
	}
}

extern "C" TESTADVCALCULATORPASS_API bool TEST() {
	bool outcome = false;
	if (exp(2, 2) == 4 && exp(3, 3) == 27 && exp(1, 0) == 1 && exp(12, 0) == 1 &&
		modulo(2, 2) == 0 && modulo(5, 2) == 1 && modulo(0, 5) == 0 &&
		factorial(2) == 2 && factorial(7) == 5040 && factorial(0) == 1 && factorial(1) == 1 &&
		gcd(12, 2) == 2 && gcd(3, 3) == 3 && gcd(4, 0) == 4 && gcd(0, 8) == 8) {
		outcome = true;
	}
	return outcome;
}