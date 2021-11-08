#pragma once
#include <iostream>
#include <string>
#include "TestLogger.h"
#include "TestTimer.h"


using namespace TestChef;
using namespace std;

class TestExceptionHandler
{
private:
	TestTimer timer;

public:
	string getCustomizedString(exception& e, LOGLEVEL logLevel, TestTimer timer);

};