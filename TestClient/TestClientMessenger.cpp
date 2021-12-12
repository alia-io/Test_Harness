#include "TestClientMessenger.h"

std::string TestClientMessenger::createJSONClientMessage()
{
	dllNames = {"TestBasicCalculatorPass.dll",		// get the list of all the DLL names
				"TestCasicCalculatorFail.dll",
				"TestBasicCalculatorTestDriverException.dll",
				"AdvCalculatorTestDriverPass",
				"MemoryAllocatorTestDriverException",
				"MemoryAllocatorTestDriverException",
				"ContainerConversionsTestDriverFail",
				"ContainerConversionsTestDriverException",
				"LengthErrorTestDriverException",
				"OverflowErrorTestDriverException"};

	numDLLs = dllNames.size();
	JSONClientMessage = "{\"count\":" + std::to_string(numDLLs) + "\"tests\":["; 	// follow the JSON format { "count": __, "Tests": [ 
	for (int i = 1; i < numDLLs; i++) {
		JSONClientMessage += "\"" + dllNames[i] + "\", ";		//iterate over creating the JSON format "test1", "test2",
	}
	JSONClientMessage += "\"" + dllNames[numDLLs] + "\"]}";
	return JSONClientMessage;
}

int TestClientMessenger::getNumDLLs(){ return numDLLs; }
