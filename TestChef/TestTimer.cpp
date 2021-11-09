#include "TestTimer.h"
#include <chrono>
#include <sstream>
#include <regex>

using  std::chrono::system_clock;
using  std::chrono::duration_cast;
using  std::chrono::nanoseconds;

void TestTimer::startTimer() {
	startTime =system_clock::now();
}

void TestTimer::endTimer() {
	endTime = system_clock::now();
}

double TestTimer::timeTaken() {
	return duration_cast<nanoseconds>(endTime - startTime).count();
}

std::string TestTimer::currentTime() {
	time_t now = system_clock::to_time_t(system_clock::now());
	char buf[30]{ '\0' };
	ctime_s(buf, sizeof(buf), &now);
	std::stringstream stream;
	stream << buf;
	std::string time = std::regex_replace(stream.str(), std::regex("\\s+$"), std::string(""));
	return time;
}