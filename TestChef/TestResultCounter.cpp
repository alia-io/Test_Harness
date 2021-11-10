#include "TestResultCounter.h"


void TestResultCounter::setTotalTests(int count) { totalTests = count; };
void TestResultCounter::incrementTestPassed() { testsPassed++; };
void TestResultCounter::incrementTestFailed() { testsFailed++; };


int TestResultCounter::getTestsPassed() { return testsPassed; };
int TestResultCounter::getTestsFailed() { return testsFailed; };
int TestResultCounter::getTestsTotal() { return totalTests; };
