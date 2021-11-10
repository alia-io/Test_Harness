#include "ContainerConversions.h"

std::list<int> ContainerConversions::vectorToList(std::vector<int> vec) {
	std::list<int> lst(vec.size());
	auto it = lst.begin();
	for (int i = 0; i < vec.size(); ++i) {		// should throw overflow_error or similar?
		*it = vec[i];
		++it;
	}
	return lst;
}

std::vector<int> ContainerConversions::listToVector(std::list<int> lst) {
	std::vector<int> vec(lst.size());
	int i = 0;
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		vec[i] = *it;
		++i;
	}
	return vec;
}