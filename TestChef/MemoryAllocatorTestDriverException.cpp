#include "ITest.h"
#include "MemoryAllocator.h"

class MemoryAllocatorTestDriverException : public ITest {
public:
	bool ITest::TEST() {		// expect std::length_error thrown
		MemoryAllocator allocator{};

		int arr[1000];
		std::vector<std::string> vec(-2);	// length_error
		std::list<double> lst(100);

		if (arr == allocator.allocIntArray(1000)
				&& vec == allocator.allocStringVector(2)
				&& lst == allocator.allocDoubleList(100)) {
			return true;
		}
	
		return false;
	}
};