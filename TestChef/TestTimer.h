#pragma once
#include <time.h>
#include <chrono>
using std::chrono::time_point;
using std::chrono::system_clock;
class TestTimer
{
private:
	time_point<system_clock> startTime;
	time_point<system_clock> endTime;

public:
	void startTimer();
	void endTimer();
	double timeTaken();
	
};

