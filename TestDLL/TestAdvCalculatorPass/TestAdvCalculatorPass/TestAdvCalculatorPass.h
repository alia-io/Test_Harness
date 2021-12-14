// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TESTADVCALCULATORPASS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TESTADVCALCULATORPASS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTADVCALCULATORPASS_EXPORTS
#define TESTADVCALCULATORPASS_API __declspec(dllexport)
#else
#define TESTADVCALCULATORPASS_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TESTADVCALCULATORPASS_API CTestAdvCalculatorPass {
public:
	CTestAdvCalculatorPass(void);
	// TODO: add your methods here.
};

extern TESTADVCALCULATORPASS_API int nTestAdvCalculatorPass;

TESTADVCALCULATORPASS_API int fnTestAdvCalculatorPass(void);

extern "C" TESTADVCALCULATORPASS_API bool TEST();