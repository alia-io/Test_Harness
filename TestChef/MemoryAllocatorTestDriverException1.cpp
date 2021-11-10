#include "ITest.h"
#include "MemoryAllocator.h"

class MemoryAllocatorTestDriverException1 : public ITest {
public:
	bool ITest::TEST() {
		MemoryAllocator allocator{};
		std::vector<std::string> vec(2);
		std::list<double> lst(100);
		if (vec == allocator.allocStringVector(-2) && lst == allocator.allocDoubleList(100)) { // expect exception here
			return true;
		}
		return false;
	}
};