#include "AdvCalculator.h"

//////////////////////////////////////////////////////
// AdvCalculator.cpp								//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Implementation of AdvCalculator class. 
* 
* This class is part of the TEST functions that the TestHarness runs through
* Each test function here is an arithmetic operation
*
*/

int AdvCalculator::exp(int operand1, int operand2) {
	if (operand2 != 0) { //check if the power is non-zero
		return (operand1 * AdvCalculator::exp(operand1, operand2 - 1)); //multiply the base with itself until power is zero
	}
	else {
		return 1; //power is zero and base^0=1
	}
}

int AdvCalculator::modulo(int operand1, int operand2) {
	return operand1 % operand2;
}

int AdvCalculator::factorial(int operand1) {
	if (operand1 != 0) { //check if the power is non-zero
		return (operand1 * AdvCalculator::factorial(operand1 - 1)); //multiply the operand with operand-1 recursively
	}
	else {
		return 1; //factorial of zero = 1
	}
}

int AdvCalculator::gcd(int operand1, int operand2) {
	if (operand1 == 0){	//return gcd of the operand that is non-zero
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

bool AdvCalculator::TEST() {
	if (exp(2, 2) == 4 && exp(3, 3) == 27 && exp(1, 0) == 1 && exp(12, 0) == 1 && 
		modulo(2, 2) == 0 && modulo(5, 2) == 1 && modulo(0, 5) == 0 &&
		factorial(2) == 2 && factorial(7) == 5040 && factorial(0) == 1 && factorial(1) == 1 &&
		gcd(12, 2) == 2 && gcd(3, 3) == 3 && gcd(4, 0) == 4 && gcd(0, 8) == 8) {
		return true;
	}
	else {
		return false;
	}

}
