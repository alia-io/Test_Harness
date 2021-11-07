#include "TestExceptionHandler.h"
using namespace TestChef;

string TestExceptionHandler::getCustomizedString(exception e, LOGLEVEL logLevel, TestTimer timer) {
	string logDetail = ""; // initialize the return string for the exception handler
	string except = e.what();
	string except_str = "";
	
	if (except == "bad_alloc") {
		except_str = "Failure to allocate storage.";
	}
	else if (except == "bad_cast") {
		except_str = "A dynamic_cast to a reference type fails the run-time check.";
	}
	else if (except == "bad_exception") {
		except_str = "Failure exception thrown during runtime.";
	}
	else if (except == "bad_typeid") {
		except_str = "A typeid operator is applied to a dereferenced null pointer value of a polymorphic type.";
	}
	else if (except == "bad_weak_ptr") {
		except_str = "A std::weak_ptr refers to an already deleted object.";
	}
	else if (except == "logic_error") {
		except_str = "Faulty logic within the program.";
	}
	else if (except == "runtime_error") {
		except_str = "Error detected during runtime.";
	}

	switch (logLevel) {
	case LOGLEVEL::info:
		logDetail = "Test failed with exception\n";
		break;
	case LOGLEVEL::detail:
		logDetail = "Test failed with the exception: " + except_str;
		break;
	case LOGLEVEL::debug:
		logDetail = "Test failed with the exception: " + except_str + "at time" + to_string(timer.timeTaken());
		break;
	}

	return logDetail;

}