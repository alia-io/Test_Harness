#pragma once
#include <iostream>
#include <string>
#include "TestTimer.h"


using namespace std;
class TestExceptionHandler
{
private:
	TestTimer timer;

public:
	string getCustomizedString(string exception, int logLevel, bool (*funcPtr)());

};