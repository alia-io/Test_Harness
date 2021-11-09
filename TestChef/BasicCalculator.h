#pragma once
#include <string>

//////////////////////////////////////////////////////
// BasicCalculator.h								//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
*
* This class is part of the TEST functions that the TestHarness runs through
* Each test function here is an arithmetic operation
*
*/
class BasicCalculator
{

public:
	int add(int operand1, int operand2);
	int subtract(int operand1, int operand2);
	int multiply(int operand1, int operand2);
	int divide(int operand1, int operand2);
	bool isZero(int number);
	bool TEST();
};

