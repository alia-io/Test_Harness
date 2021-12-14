#include "TestDLLLoader.h"
#include <iostream>
#include <windows.h>
using std::cout;

bool TestDLLLoader::dllLoader(std::string dllName) {
	testFunc importedFunctionPointer;
	std::string funcName = "TEST"; //default function expected in all dlls
	bool outcome = false;
	//loads dll
	HINSTANCE hinstLib = LoadLibraryA(dllName.c_str());

	std::cout << "dllName = " << dllName << std::endl;

	if (hinstLib)
	{
		//assigning function pointer
		//std::cout << "hinstLib" << std::endl;
		importedFunctionPointer = (testFunc)(GetProcAddress(hinstLib, funcName.c_str()));

		if (importedFunctionPointer)
		{
			//std::cout << "importedFunctionPointer" << std::endl;
			outcome = importedFunctionPointer();
			std::cout << "outcome = " << outcome << std::endl;
		}
		else
			cout << "Could Not Load function " << std::endl;
	}
	else
		cout << "Could Not Load DLL " << std::endl;
	return outcome;
}
