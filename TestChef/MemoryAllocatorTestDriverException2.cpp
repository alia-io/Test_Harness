#include "ITest.h"
#include "MemoryAllocator.h"

class MemoryAllocatorTestDriverException2 : public ITest {
public:
	bool ITest::TEST() {
		MemoryAllocator allocator{};
		std::vector<std::string> vec = allocator.allocStringVector(5);
		if (vec.at(5) != "\0") {
			return false;
		}
		return true;
	}
};