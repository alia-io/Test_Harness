#include "MemoryAllocator.h"
#include "TestRunner.h"
#include <iostream>

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
	try {
		return new int[sz];
	}
	catch (std::bad_alloc) {
		std::cout << "bad alloc error" << std::endl;
	}
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

// TEST function: expect std::length_error thrown
bool TEST() {

	MemoryAllocator allocator{};

	int arr[1000];
	std::vector<std::string> vec(-2);	// length_error
	std::list<double> lst(100);

	if (arr == allocator.allocIntArray(1000)
			&& vec == allocator.allocStringVector(2)
			&& lst == allocator.allocDoubleList(100)) {
		return true;
	}
	
	return false;
}

int main() {
	TestLogger logger1{LOGLEVEL::debug};
	TestRunner runner1{ "MemoryAllocator::TEST", *TEST };
	bool result1 = runner1.runTest(logger1);
}