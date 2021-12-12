// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TESTBASICCALCULATORPASS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TESTBASICCALCULATORPASS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTBASICCALCULATORPASS_EXPORTS
#define TESTBASICCALCULATORPASS_API __declspec(dllexport)
#else
#define TESTBASICCALCULATORPASS_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TESTBASICCALCULATORPASS_API CTestBasicCalculatorPass {
public:
	CTestBasicCalculatorPass(void);
	// TODO: add your methods here.
};

extern TESTBASICCALCULATORPASS_API int nTestBasicCalculatorPass;

TESTBASICCALCULATORPASS_API int fnTestBasicCalculatorPass(void);

extern "C" TESTBASICCALCULATORPASS_API bool TEST();

