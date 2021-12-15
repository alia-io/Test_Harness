// TestMemoryAllocaterException02.cpp : Defines the exported functions for the DLL.
//


#pragma once
#include "pch.h"
#include "framework.h"
#include "TestMemoryAllocaterException02.h"
#include <vector>
#include <list>
#include <string>


// This is an example of an exported variable
TESTMEMORYALLOCATEREXCEPTION02_API int nTestMemoryAllocaterException02=0;

// This is an example of an exported function.
TESTMEMORYALLOCATEREXCEPTION02_API int fnTestMemoryAllocaterException02(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTestMemoryAllocaterException02::CTestMemoryAllocaterException02()
{
    return;
}

// allocates a vector of strings of size 'sz'.
std::vector<std::string> allocStringVector(int sz) {
	std::vector<std::string> vec(sz);
	return vec;
}

// allocates a list of doubles of size 'sz'.
std::list<double> allocDoubleList(int sz) {
	std::list<double> lst(sz);
	return lst;
}

extern "C" TESTMEMORYALLOCATEREXCEPTION02_API bool TEST() {
	std::vector<std::string> vec(2);
	std::list<double> lst(100);
	if (vec == allocStringVector(-2) && lst == allocDoubleList(100)) { // expect exception here
		return true;
	}
	return false;
}