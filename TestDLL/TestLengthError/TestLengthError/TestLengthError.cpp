// TestLengthError.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "TestLengthError.h"
#include <vector>


// This is an example of an exported variable
TESTLENGTHERROR_API int nTestLengthError=0;

// This is an example of an exported function.
TESTLENGTHERROR_API int fnTestLengthError(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTestLengthError::CTestLengthError()
{
    return;
}


extern "C" TESTLENGTHERROR_API bool TEST() {
    std::vector<int> vec;
    vec.resize(vec.max_size() + 1);
    return true;
}