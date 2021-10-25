#include "BasicCalculator.h"


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