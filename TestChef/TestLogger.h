#pragma once
#include "TestTimer.h"
#include "TestResultCounter.h"
#include "TestMessageParser.h"
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
		void writeLogInfoToOutput(TEST_RESULT result, std::string message, TestTimer timer);
		LOGLEVEL getLogLevel();
		void setLogLevel(LOGLEVEL log);
		void writeTestRunSummary(TestResultCounter counter, TestTimer timer);
	};

};


