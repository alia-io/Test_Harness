#pragma once
#include <string>
#include <vector>
class TestClientMessenger {
private:
	int numDLLs;						//indicates the number of DLLs
	std::vector<std::string> dllNames;
	std::string JSONClientMessage;

public:
	std::string createJSONClientMessage();
	int getNumDLLs();
};