#pragma once
#include "TestTimer.h"
#include "TestResultCounter.h"
#include <string>

//////////////////////////////////////////////////////
// TestLogger.h										//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
*
* This class is retrieve the logLevel and print the exception messages to a file.
* This class also includes a function for summarizing the test results into a pass/failed section
* 
*/

namespace TestChef {
	enum class LOGLEVEL {
		info, debug, detail
	};
	class TestLogger
	{
	private:
		LOGLEVEL logLevel;
	public:
		TestLogger(LOGLEVEL);
		TestLogger();
		void writeLogInfoToFile(std::string message, TestTimer timer);
		void writeLogInfoToFile(std::string message, TestTimer timer, bool outcome);
		LOGLEVEL getLogLevel();
		void setLogLevel(LOGLEVEL log);
		void printTestRunSummary(TestResultCounter counter, TestTimer timer);
	};

};


