#include "TestExceptionHandler.h"

string TestExceptionHandler::getCustomizedString(string exception, int logLevel, bool (*funcPtr)()) {
	string logDetail = ""; // initialize the return string for the exception handler

	switch (logLevel) {
	case 1:
		logDetail = "Test failed with exception\n";
		break;
	case 2:
		logDetail = "Test failed with the exception: " + exception;
	case 3:
		logDetail = logDetail + "at time" + std::to_string(timer.timeTaken());
		break;
	}

	return logDetail;

}