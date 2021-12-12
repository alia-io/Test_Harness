#include "TestDLLLoader.h"
#include <iostream>
#include <windows.h>
using std::cout;

void TestDLLLoader::dllLoader(std::string dllName) {
	//pointer to the function obtained from .dll
	testFunc importedFunctionPointer;
	std::string funcName = "TEST";

	//load .dll into memory;
	HINSTANCE hinstLib = LoadLibraryA(dllName.c_str());
	//add the memory location of the library to the all_DLL_MemoryLocations vector
	//this->all_DLL_MemoryLocations.push_back(current_DLL_MemoryLocation);

	if (hinstLib)
	{
		// function pointer pointing to memory location of the function in the .dll
		importedFunctionPointer = (testFunc)(GetProcAddress(hinstLib, funcName.c_str()));

		if (importedFunctionPointer)
		{
			cout << "Function Output -->" << importedFunctionPointer();
		}
		else
			cout << "Could Not Load function " << std::endl;
	}
	else
		cout << "Could Not Load DLL " << std::endl;
}
