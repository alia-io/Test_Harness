#pragma once
#include <string>
using std::string;

class TestDLLLoader {
public:
	void dllLoader(string dllName);
private:
	typedef bool(__cdecl* testFunc)();

};