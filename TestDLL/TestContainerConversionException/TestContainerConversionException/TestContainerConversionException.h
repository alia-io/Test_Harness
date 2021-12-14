// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TESTCONTAINERCONVERSIONEXCEPTION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TESTCONTAINERCONVERSIONEXCEPTION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTCONTAINERCONVERSIONEXCEPTION_EXPORTS
#define TESTCONTAINERCONVERSIONEXCEPTION_API __declspec(dllexport)
#else
#define TESTCONTAINERCONVERSIONEXCEPTION_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TESTCONTAINERCONVERSIONEXCEPTION_API CTestContainerConversionException {
public:
	CTestContainerConversionException(void);
	// TODO: add your methods here.
};

extern TESTCONTAINERCONVERSIONEXCEPTION_API int nTestContainerConversionException;

TESTCONTAINERCONVERSIONEXCEPTION_API int fnTestContainerConversionException(void);

extern "C" TESTCONTAINERCONVERSIONEXCEPTION_API bool TEST();
