#pragma once
#include <time.h>
#include <chrono>
#include <string>

//////////////////////////////////////////////////////
// TestTimer.h										//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* This class is used to report current time as well as instantiated time slices.
*
*/

using std::chrono::time_point;
using std::chrono::system_clock;

class Timer {
private:
	time_point<system_clock> startTime;
	time_point<system_clock> endTime;
public:
	void startTimer();
	void endTimer();
	double timeTakenNanos();
	double timeTakenMillis();
	double timeTakenSeconds();
	static std::string convertTimeToString(double t);
	static std::string currentTime();
	static int64_t epochTimeFromTimePoint(time_point<system_clock> timestamp);
	static time_point<system_clock> timePointFromEpochTime(std::string epochTime);
};

