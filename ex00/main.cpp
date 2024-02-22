#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void) {
	std::vector<int> vec;

	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	easyfind(vec, -3);
	easyfind(vec, 3);
}