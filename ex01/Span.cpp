#include <iostream>
#include <limits>
#include <cstdlib>
#include "Span.hpp"

//constructors/destructors
Span::Span(void): _size(0) {

}

Span::~Span(void){

}

Span::Span(unsigned int size): _size(size) {
	
}

Span::Span(const Span& other): _size(other._size) {
	
}

//methods

void Span::addNumber(int num) {
	if (_list.size() >= _size) {
		throw InvalidNumbersException();
		return;
	}
	_list.push_back(num);
}

unsigned int Span::shortestSpan(void) {
	if (_list.size() < 2) {
		throw InvalidNumbersException();
		return 0;
	}
	unsigned int shortSpan = UINT32_MAX;
	unsigned int distAbs;
	std::list<int>::iterator ptr[2];
	for (ptr[0] = _list.begin(); ptr[0] < _list.end(); ptr[0]++) {
		for (ptr[1] = _list.begin(); ptr[1] < _list.end(); ptr[1]++) {
			distAbs = (unsigned int)abs(*ptr[0] - *ptr[1]);
			if (distAbs < shortSpan)
				shortSpan = distAbs;
		}
	}
	return shortSpan;
}

unsigned int	Span::longestSpan(void) {
	if (_list.size() < 2) {
		throw InvalidNumbersException();
		return 0;
	}
	int longSpan = 0;
	unsigned int distAbs;
	std::list<int>::iterator ptr[2];
	for (ptr[0] = _list.begin(); ptr[0] < _list.end(); ptr[0]++) {
		for (ptr[1] = _list.begin(); ptr[1] < _list.end(); ptr[1]++) {
			distAbs = (unsigned int)abs(*ptr[0] - *ptr[1]);
			if (distAbs > longSpan)
				longSpan = distAbs;
		}
	}
	return longSpan;
}

//operators

const Span& Span::operator=(const Span& other) {
	return *this;
}

//exceptions

const char* Span::InvalidNumbersException::what(void) const throw() {
	return "Invalid amount of numbers";
}

//ostream

std::ostream& operator<<(std::ostream& out, const Span& span) {
	out << "span" << std::endl;
	return out;
}