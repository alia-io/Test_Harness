// TestContainerConversionException.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "TestContainerConversionException.h"
#include <list>
#include <vector>


// This is an example of an exported variable
TESTCONTAINERCONVERSIONEXCEPTION_API int nTestContainerConversionException=0;

// This is an example of an exported function.
TESTCONTAINERCONVERSIONEXCEPTION_API int fnTestContainerConversionException(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTestContainerConversionException::CTestContainerConversionException()
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
extern "C" TESTCONTAINERCONVERSIONEXCEPTION_API bool TEST() {
	std::list<int> lst = { 1, 2, 3, 4, 5 };
	std::vector<int> vec = listToVector(lst);
	vec.at(5) = 6;				// this will cause an exception
	int i = 0;
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		if (vec[i] != *it) {
			if (i == vec.size())
				return true;
			else
				return false;
		}
	}
	return true;

}