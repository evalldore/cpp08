#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

template<typename T>
int easyfind(T& var, int num) {
	if (std::find(var.begin(), var.end(), num) != var.end()) {
		std::cout << "Found " << num << " in container!" << std::endl;
		return 1;
	}
	std::cout << "Missing " << num << " in container!" << std::endl;
	return 0;
}
