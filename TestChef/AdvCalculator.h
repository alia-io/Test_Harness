#pragma once
#include <string>

//////////////////////////////////////////////////////
// AdvCalculator.h									//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
*
* This class is part of the TEST functions that the TestHarness runs through 
* Each test function here is an arithmetic operation
*
*/

class AdvCalculator
{

public:
	int exp(int operand1, int operand2);
	int modulo(int operand1, int operand2);
	int factorial(int operand1);
	int gcd(int operand1, int operand2);
	bool TEST();
};

