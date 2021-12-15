#include "DllLoader.h"
#include <iostream>
#include <windows.h>
using std::cout;

//////////////////////////////////////////////////////
// TestDLLLoader.cpp									//
// CSE 687: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Implementation of Test DLLoader Class
*
* Purpose of class is load the dlls based on the name and execute the function TEST which returns a bool value
*
*/

bool DllLoader::dllLoader(std::string dllName) {
	testFunc importedFunctionPointer;
	std::string funcName = "TEST"; //default function expected in all dlls
	bool outcome = false;
	//loads dll
	HINSTANCE hinstLib = LoadLibraryA(dllName.c_str());

	if (hinstLib)
	{
		//assigning function pointer
		importedFunctionPointer = (testFunc)(GetProcAddress(hinstLib, funcName.c_str()));

		if (importedFunctionPointer)
		{
			outcome = importedFunctionPointer();
		}
		else
			cout << "Could Not Load function " << std::endl;
	}
	else
		cout << "Could Not Load DLL " << std::endl;
	return outcome;
}
