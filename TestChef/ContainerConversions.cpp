#include "ContainerConversions.h"

template <typename T>
std::list<T> ContainerConversions::vectorToList(std::vector<T> vec) {
	std::list<T> lst(vec.size());
	auto it = lst.begin();
	for (int i = 0; i < vec.size(); ++i) {		// should throw overflow_error?
		*it = vec[i];
		++it;
	}
	return lst;
}

template <typename T>
std::vector<T> ContainerConversions::listToVector(std::list<T> lst) {

}

bool ContainerConversions::TEST() {

	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::list<int> lst = vectorToList(vec);

	int i = 0;
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		if (vec[i] != *it) return false;
		++i;
	}

	return true;
}