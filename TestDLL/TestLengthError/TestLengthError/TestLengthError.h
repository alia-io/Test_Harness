// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TESTLENGTHERROR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TESTLENGTHERROR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTLENGTHERROR_EXPORTS
#define TESTLENGTHERROR_API __declspec(dllexport)
#else
#define TESTLENGTHERROR_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TESTLENGTHERROR_API CTestLengthError {
public:
	CTestLengthError(void);
	// TODO: add your methods here.
};

extern TESTLENGTHERROR_API int nTestLengthError;

TESTLENGTHERROR_API int fnTestLengthError(void);

extern "C" TESTLENGTHERROR_API bool TEST();
