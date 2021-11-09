#include "BasicCalculator.h"

//////////////////////////////////////////////////////
// BasicCalculator.cpp								//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Implementation of BasicCalculator class.
*
* This class is part of the TEST functions that the TestHarness runs through
* Each test function here is an arithmetic operation
*
*/

int BasicCalculator::add(int operand1, int operand2) {
	return operand1 + operand2;
}

int BasicCalculator::subtract(int operand1, int operand2) {
	return operand1 - operand2;
}

int BasicCalculator::multiply(int operand1, int operand2) {
	return operand1 * operand2;
}

int BasicCalculator::divide(int operand1, int operand2) {
	return operand1 / operand2;
}

bool BasicCalculator::isZero(int number) {
	bool result = false;
	if (number != 0) {
		result = true;
	}
	return result;
}

bool BasicCalculator::TEST() {
	if (add(2, 2) == 4 && add(3, 3) == 9 && add(1, 0) == 1 && add(0, 12) == 12 &&
		subtract(2, 2) == 0 && subtract(5, 2) == 3 && subtract(0, 5) == -5 && subtract(5, 0) == 5 &&
		multiply(2, 1) == 2 && multiply(-7, 7) == -49 && multiply(0, 0) == 0 && multiply(-4,-3) == 12 &&
		divide(12, 2) == 6 && divide(3, 3) == 1 && divide(0, 4) == 0 && divide(15, 1) == 15) {
		return true;
	}
	else {
		return false;
	}

}