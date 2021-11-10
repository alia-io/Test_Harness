#pragma once
class TestResultCounter
{
private:
	int testsPassed;
	int testsFailed;
	int totalTests;
public :
	void setTotalTests(int count);
	void incrementTestPassed();
	void incrementTestFailed();
	int getTestsPassed();
	int getTestsFailed();
	int getTestsTotal();
};

