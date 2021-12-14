#include "Timer.h"
#include <chrono>
#include <sstream>
#include <regex>

//////////////////////////////////////////////////////
// TestTimer.cpp									//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Implementation of the TestTimer class.
* This class is used to report current time as well as instantiated time slices.
*
*/

using std::chrono::system_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::milliseconds;
using std::chrono::seconds;

void Timer::startTimer() {
	startTime = system_clock::now();	// Sets a start time when called.  
}

void Timer::endTimer() {
	endTime = system_clock::now(); // Sets an end time when called.
}

double Timer::timeTakenNanos() {
	return duration_cast<nanoseconds>(endTime - startTime).count();
}

double Timer::timeTakenMillis() {
	return duration_cast<milliseconds>(endTime - startTime).count();
}

double Timer::timeTakenSeconds() {
	return duration_cast<seconds>(endTime - startTime).count();
}

std::string Timer::convertTimeToString(double t) {
	std::string rawTime = std::to_string(t);
	std::string outTime = "";
	for (char ch : rawTime) {
		if (ch == '.') break;
		outTime += ch;
	}
	return outTime;
}

std::string Timer::currentTime() {		// Function that returns formatted current time
	time_t now = system_clock::to_time_t(system_clock::now());
	char buf[30]{ '\0' };
	ctime_s(buf, sizeof(buf), &now);
	std::stringstream stream;
	stream << buf;
	std::string time = std::regex_replace(stream.str(), std::regex("\\s+$"), std::string(""));
	return time;
}