#pragma once
#include "Timer.h"
#include "StaticLogger.h"
#include <string>
#include <iostream>

//////////////////////////////////////////////////////
// Result.h										//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Header of the ResultFormatter class
* This class is used to return the results of each test that is run.
* Each test is run at a specific log level and that level determines the level of detail that is passed into the test result
*
*/

class ResultFormatter {
public:
	static std::string testPassedMessage(std::string testName, Timer timer);
	static std::string testFailedMessage(std::string testName, Timer timer);
	static std::string testExceptionMessage(std::string testName, std::exception& e, LOG_LEVEL logLevel);
private:
	static std::string exceptionDetails(std::exception& e);
};