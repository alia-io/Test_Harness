// TestContainerConversionFail.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "TestContainerConversionFail.h"

#include <list>
#include <vector>


// This is an example of an exported variable
TESTCONTAINERCONVERSIONFAIL_API int nTestContainerConversionFail=0;

// This is an example of an exported function.
TESTCONTAINERCONVERSIONFAIL_API int fnTestContainerConversionFail(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTestContainerConversionFail::CTestContainerConversionFail()
{
    return;
}

std::list<int> vectorToList(std::vector<int> vec) {
	std::list<int> lst(vec.size());
	auto it = lst.begin();
	for (int i = 0; i < vec.size(); ++i) {		// should throw overflow_error or similar?
		*it = vec[i];
		++it;
	}
	return lst;
}

std::vector<int> listToVector(std::list<int> lst) {
	std::vector<int> vec(lst.size());
	int i = 0;
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		vec[i] = *it;
		++i;
	}
	return vec;
}

extern "C" TESTCONTAINERCONVERSIONFAIL_API bool TEST() {
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::list<int> lst = vectorToList(vec);
	int i = 1;							// this will cause a fail
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		if (vec[i] != *it) return false;
		++i;
	}
	return true;
}