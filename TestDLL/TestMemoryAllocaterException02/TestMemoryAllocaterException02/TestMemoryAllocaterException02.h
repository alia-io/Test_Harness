// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TESTMEMORYALLOCATEREXCEPTION02_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TESTMEMORYALLOCATEREXCEPTION02_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTMEMORYALLOCATEREXCEPTION02_EXPORTS
#define TESTMEMORYALLOCATEREXCEPTION02_API __declspec(dllexport)
#else
#define TESTMEMORYALLOCATEREXCEPTION02_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TESTMEMORYALLOCATEREXCEPTION02_API CTestMemoryAllocaterException02 {
public:
	CTestMemoryAllocaterException02(void);
	// TODO: add your methods here.
};

extern TESTMEMORYALLOCATEREXCEPTION02_API int nTestMemoryAllocaterException02;

TESTMEMORYALLOCATEREXCEPTION02_API int fnTestMemoryAllocaterException02(void);

extern "C" TESTMEMORYALLOCATEREXCEPTION02_API bool TEST();
