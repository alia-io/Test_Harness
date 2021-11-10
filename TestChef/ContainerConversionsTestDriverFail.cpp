#include "ITest.h"
#include "ContainerConversions.h"

class ContainerConversionsTestDriverFail : public ITest {
public:
	bool ITest::TEST() {
		ContainerConversions converter{};
		std::vector<int> vec = { 1, 2, 3, 4, 5 };
		std::list<int> lst = converter.vectorToList(vec);
		int i = 1;							// this will cause a fail
		for (auto it = lst.begin(); it != lst.end(); ++it) {
			if (vec[i] != *it) return false;
			++i;
		}
		return true;
	}
};