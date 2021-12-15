// TestOverFlowException.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "TestOverFlowException.h"
#include <bitset>


// This is an example of an exported variable
TESTOVERFLOWEXCEPTION_API int nTestOverFlowException=0;

// This is an example of an exported function.
TESTOVERFLOWEXCEPTION_API int fnTestOverFlowException(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTestOverFlowException::CTestOverFlowException()
{
    return;
}

extern "C" TESTOVERFLOWEXCEPTION_API bool TEST() {

	std::bitset<100> bs;
	bs[99] = 1;
	bs[0] = 1;
	unsigned long ul = bs.to_ulong();
	return true;
}