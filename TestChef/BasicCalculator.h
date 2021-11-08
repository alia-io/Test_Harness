#pragma once
#include <string>
class BasicCalculator
{

public:
	int add(int operand1, int operand2);
	int subtract(int operand1, int operand2);
	int multiply(int operand1, int operand2);
	int divide(int operand1, int operand2);
	bool isZero(int number);
	bool test();
};

