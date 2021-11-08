#include "MemoryAllocator.h"
#include "TestRunner.h"

//////////////////////////////////////////////////////
// MemoryAllocator.cpp								//
// CSE 681: Object Oriented Design					//
// Santhosh Srinivasan, Jiawen Zhen, Alifa Stith	//
//////////////////////////////////////////////////////

/*
* Implementation of MemoryAllocator class.
* 
* This class is used to Test the application by allocating memory for containers
* correctly or incorrectly. The main purpose of this class is to throw an exception,
* which should be caught and logged by the test harness.
*/

// allocates an integer array of size 'sz'. NOTE: this should throw a std::bad_alloc exception
int* MemoryAllocator::allocIntArray(int sz) {
	return new int[sz];
}

// allocates a vector of strings of size 'sz'.
std::vector<std::string> MemoryAllocator::allocStringVector(int sz) {
	std::vector<std::string> vec(sz);
	return vec;
}

// allocates a list of doubles of size 'sz'.
std::list<double> MemoryAllocator::allocDoubleList(int sz) {
	std::list<double> lst(sz);
	return lst;
}

// TEST function
bool TEST() {

	MemoryAllocator allocator{};
	int size = 10000;

	int arr[10000];
	std::vector<std::string> vec(size);
	std::list<double> lst(size);

	if (arr == allocator.allocIntArray(size)
			&& vec == allocator.allocStringVector(size)
			&& lst == allocator.allocDoubleList(size)) {
		return true;
	}
	else return false;
}

int main() {
	TestLogger logger1{};
	TestRunner runner1{ "testFunc1", *TEST };
	bool result1 = runner1.runTest(logger1);
}