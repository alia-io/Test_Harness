#pragma once
#include <list>
#include <vector>

class ContainerConversions {
public:
	template <typename T> std::list<T> vectorToList(std::vector<T>);
	template <typename T> std::vector<T> listToVector(std::list<T>);
	bool TEST();
};