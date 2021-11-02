#include "TestExceptionHandler.h"
using namespace TestChef;

string TestExceptionHandler::getCustomizedString(exception e, LOGLEVEL logLevel, TestTimer timer) {
	string logDetail = ""; // initialize the return string for the exception handler
	string except = e.what();
	
	switch (logLevel) {
	case LOGLEVEL::info:
		logDetail = "Test failed with exception\n";
		break;
	case LOGLEVEL::detail:
		logDetail = "Test failed with the exception: " + except;
		break;
	case LOGLEVEL::debug:
		logDetail = "Test failed with the exception: " + except + "at time" + to_string(timer.timeTaken());
		break;
	}

	return logDetail;

}