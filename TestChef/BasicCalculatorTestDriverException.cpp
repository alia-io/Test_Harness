#include "ITest.h"
#include "BasicCalculator.h"
class BasicCalculatorTestDriverException : public ITest {
public:
	bool ITest::TEST() {
		BasicCalculator calc;
		bool outcome = false;
		if (calc.divide(12, 0) == 6) {
			outcome = true;
		}
		return outcome;
	}
};