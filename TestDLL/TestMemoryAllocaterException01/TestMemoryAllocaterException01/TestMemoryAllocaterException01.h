// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TESTMEMORYALLOCATEREXCEPTION01_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TESTMEMORYALLOCATEREXCEPTION01_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTMEMORYALLOCATEREXCEPTION01_EXPORTS
#define TESTMEMORYALLOCATEREXCEPTION01_API __declspec(dllexport)
#else
#define TESTMEMORYALLOCATEREXCEPTION01_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TESTMEMORYALLOCATEREXCEPTION01_API CTestMemoryAllocaterException01 {
public:
	CTestMemoryAllocaterException01(void);
	// TODO: add your methods here.
};

extern TESTMEMORYALLOCATEREXCEPTION01_API int nTestMemoryAllocaterException01;

TESTMEMORYALLOCATEREXCEPTION01_API int fnTestMemoryAllocaterException01(void);

extern "C" TESTMEMORYALLOCATEREXCEPTION01_API bool TEST();
