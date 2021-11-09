#include "TestLogger.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace TestChef;
using std::cout;
using std::endl;

TestLogger::TestLogger(LOGLEVEL log) :logLevel(log) {

}

TestLogger::TestLogger() : logLevel(LOGLEVEL::info) {

}

void TestLogger::writeLogInfoToFile(std::string message, TestTimer timer) {
	cout << message << endl;
	cout << "Time elapsed: " << timer.timeTaken() << " ns.\n" << endl;
}

LOGLEVEL TestLogger::getLogLevel() { return logLevel; }

void TestLogger::setLogLevel(LOGLEVEL log) {
	logLevel = log;
}