#pragma once
#include <string>
using std::string;

//////////////////////////////////////////////////////
// TestDLLLoader.h									//
// CSE 687: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Test DLLoader Class
*
* Purpose of class is load the dlls based on the name and execute the function TEST which returns a bool value
*
*/

class TestDLLLoader {
public:
	bool dllLoader(string dllName);
private:
	typedef bool(__cdecl* testFunc)();

};