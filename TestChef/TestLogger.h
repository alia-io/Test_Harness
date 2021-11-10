#pragma once
#include "TestTimer.h"
#include "TestResultCounter.h"
#include <string>
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


