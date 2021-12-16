#include "Client.h"
#include <iostream>
#include <windows.h>

int main() {

	::Sleep(5000);	// delay to set up consoles

	std::list<std::string> testList{	// create a test list for all dll tests to be passed on to the server
		"TestBasicCalculatorPass", "TestBasicCalculatorFail", "TestBasicCalculatorException", "TestAdvCalculatorPass",
		"TestMemoryAllocaterException01", "TestMemoryAllocaterException02", "TestContainerConversionFail",
		"TestContainerConversionException", "TestLengthError", "TestOverflowException"
	};

	Client{}.runTests(LOG_LEVEL::debug, testList);	// ask the client to send those dlls to be run

	return 0;
}