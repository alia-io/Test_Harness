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
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "[Exception] ";
	SetConsoleTextAttribute(hConsole, 15);
	cout << message << endl;
	cout << "Time elapsed: " << timer.timeTaken() << " ns.\n" << endl;
}

void TestLogger::writeLogInfoToFile(std::string message, TestTimer timer,bool outcome) {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (outcome) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << "[Pass]";
	}
	else {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[Fail]";
	}
	SetConsoleTextAttribute(hConsole, 15);
	cout << message ;
	cout << " Time elapsed: " << timer.timeTaken() << " ns.\n" << endl;
}

LOGLEVEL TestLogger::getLogLevel() { return logLevel; }

void TestLogger::setLogLevel(LOGLEVEL log) {
	logLevel = log;
}