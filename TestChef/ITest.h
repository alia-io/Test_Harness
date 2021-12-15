#pragma once
//////////////////////////////////////////////////////
// ITest.h									//
// CSE 687: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* ITest class
*
* Purpose of class to have virtual function which is requirfed for all testdrivers to implement
*
*/
class ITest {
public:
	virtual bool TEST() = 0;
};