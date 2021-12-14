#include "Client.h"
#include <iostream>
#include <windows.h>

int main() {

	::Sleep(5000);	// delay to set up consoles

	std::list<std::string> testList{	// create a test list for all dll tests to be passed on to the server
		"TestBasicCalculatorPass", "TestBasicCalculatorFail", "TestBasicCalculatorException", "TestAdvancedCalculatorPass",
		"TestMemoryAllocatorException1", "TestMemoryAllocatorException2", "TestContainerConversionsFail",
		"TestContainerConversionsException", "TestLengthErrorException", "TestOverflowErrorException"
	};

	Client{}.runTests(LOG_LEVEL::detail, testList);	// ask the client to send those dlls to be run

	return 0;
}