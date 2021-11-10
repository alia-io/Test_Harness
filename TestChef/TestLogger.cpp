#include "TestLogger.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace TestChef;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::left;
using std::right;




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


void TestLogger::printTestRunSummary(TestResultCounter counter,TestTimer timer) {
	cout << "Test Result Summary" << endl;
	cout << "-------------------" << endl;
	cout << left << setw(10) << "Total Tests " << right << setw(10) << counter.getTestsTotal() << endl;
	cout << left << setw(10) << "Tests Passed" << right << setw(10) << counter.getTestsPassed() << endl;
	cout << left << setw(10) << "Tests Failed" << right << setw(10) << counter.getTestsFailed() << endl;
	//TODO:Add timer logic,below line gives a weird format
	//cout << left << setw(10) << "Time Taken " << right << setw(20) << timer.timeTaken() << endl;
}