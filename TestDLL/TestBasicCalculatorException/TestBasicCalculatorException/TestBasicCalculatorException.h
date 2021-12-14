// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TESTBASICCALCULATOREXCEPTION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TESTBASICCALCULATOREXCEPTION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTBASICCALCULATOREXCEPTION_EXPORTS
#define TESTBASICCALCULATOREXCEPTION_API __declspec(dllexport)
#else
#define TESTBASICCALCULATOREXCEPTION_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TESTBASICCALCULATOREXCEPTION_API CTestBasicCalculatorException {
public:
	CTestBasicCalculatorException(void);
	// TODO: add your methods here.
};

extern TESTBASICCALCULATOREXCEPTION_API int nTestBasicCalculatorException;

TESTBASICCALCULATOREXCEPTION_API int fnTestBasicCalculatorException(void);

extern "C" TESTBASICCALCULATOREXCEPTION_API bool TEST();
