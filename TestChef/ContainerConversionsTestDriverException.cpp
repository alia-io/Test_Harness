#include "ITest.h"
#include "ContainerConversions.h"

class ContainerConversionsTestDriverException : public ITest {
public:
	/*bool ITest::TEST() {

		ContainerConversions converter{};

		std::vector<int> vec = { 1, 2, 3, 4, 5 };
		std::list<int> lst = converter.vectorToList(vec);

		int i = 1;			// this will cause a fail
		for (auto it = lst.begin(); it != lst.end(); ++it) {
			if (vec[i] != *it) return false;
			++i;
		}

		return true;
	}*/

	bool ITest::TEST() {

		ContainerConversions converter{};

		std::list<int> lst = { 1, 2, 3, 4, 5 };
		std::vector<int> vec = converter.listToVector(lst);
		vec.at(5) = 6;				// this will cause an exception

		int i = 0;
		for (auto it = lst.begin(); it != lst.end(); ++it) {
			if (vec[i] != *it) {
				if (i == vec.size())
					return true;
				else
					return false;
			}
		}

		return true;
	}
};