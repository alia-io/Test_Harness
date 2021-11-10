#pragma once
#include <list>
#include <vector>

class ContainerConversions {
public:
	std::list<int> vectorToList(std::vector<int>);
	std::vector<int> listToVector(std::list<int>);
};