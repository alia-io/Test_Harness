#include "TestExceptionHandler.h"
using namespace TestChef;

string TestExceptionHandler::getCustomizedString(exception& e, LOGLEVEL logLevel, TestTimer timer) {
	string logDetail = ""; // initialize the return string for the exception handler
	string except_str = "";
	
	if (typeid(e) == typeid(std::bad_alloc)) {
		except_str = "Failure to allocate storage.";
	}
	else if (typeid(e) == typeid(std::bad_cast)) {
		except_str = "A dynamic_cast to a reference type fails the run-time check.";
	}
	else if (typeid(e) == typeid(std::bad_exception)) {
		except_str = "Failure exception thrown during runtime.";
	}
	else if (typeid(e) == typeid(std::bad_typeid)) {
		except_str = "A typeid operator is applied to a dereferenced null pointer value of a polymorphic type.";
	}
	else if (typeid(e) == typeid(std::bad_weak_ptr)) {
		except_str = "A std::weak_ptr refers to an already deleted object.";
	}
	else if (typeid(e) == typeid(std::logic_error)) {
		except_str = "Faulty logic within the program.";
	}
	else if (typeid(e) == typeid(std::runtime_error)) {
		except_str = "Error detected during runtime.";
	}
	else if (typeid(e) == typeid(std::length_error)) {
		except_str = "Attempt to exceed implementation defined length limits for some object.";
	}

	switch (logLevel) {
	case LOGLEVEL::info:
		logDetail = "\nTest failed with exception.";
		break;
	case LOGLEVEL::detail:
		logDetail = "\nTest failed with the exception: " + except_str;
		break;
	case LOGLEVEL::debug:
		
		logDetail = "\nTest failed with the exception: " + except_str + "\nException occurred on " + timer.currentTime() + ".";
		break;
	}

	return logDetail;

}