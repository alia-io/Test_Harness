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
	return nullptr;
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