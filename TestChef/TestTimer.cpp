#include "TestTimer.h"
#include <chrono>
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