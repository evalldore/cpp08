#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator		iterator;

		iterator begin(void) {return std::stack<T>::c.begin();}
		iterator end(void) {return std::stack<T>::c.end();}
};