#pragma once
#include "TestTimer.h"
#include <string>
namespace TestChef {
	enum class LOGLEVEL {
		info,debug,detail
	};
class TestLogger
	{
	private:
		LOGLEVEL logLevel;
	public:
		TestLogger(LOGLEVEL);
		TestLogger();
		void writeLogInfoToFile(std::string message,TestTimer timer);
	};

}

