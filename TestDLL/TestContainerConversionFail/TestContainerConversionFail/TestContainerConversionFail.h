// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TESTCONTAINERCONVERSIONFAIL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TESTCONTAINERCONVERSIONFAIL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTCONTAINERCONVERSIONFAIL_EXPORTS
#define TESTCONTAINERCONVERSIONFAIL_API __declspec(dllexport)
#else
#define TESTCONTAINERCONVERSIONFAIL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TESTCONTAINERCONVERSIONFAIL_API CTestContainerConversionFail {
public:
	CTestContainerConversionFail(void);
	// TODO: add your methods here.
};

extern TESTCONTAINERCONVERSIONFAIL_API int nTestContainerConversionFail;

TESTCONTAINERCONVERSIONFAIL_API int fnTestContainerConversionFail(void);

extern "C" TESTCONTAINERCONVERSIONFAIL_API bool TEST();
