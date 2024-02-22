#include <iostream>
#include "Span.hpp"

//constructors/destructors
Span::Span(void): _size(0) {

}

Span::~Span(void){

}

Span::Span(unsigned int size): _size(0) {
	
}

Span::Span(const Span& other): _size(other._size) {
	
}

//methods

void	Span::addNumber(int num) {
	if (_list.size() >= _size) {
		throw InvalidNumbersException();
		return;
	}
	_list.push_back(num);
}

unsigned int	Span::shortestSpan(void) {
	if (_list.size() < 2) {
		throw InvalidNumbersException();
		return 0;
	}
	int shortSpan = 0;
	return (shortSpan);
}

unsigned int	Span::longestSpan(void) {
	if (_list.size() < 2) {
		throw InvalidNumbersException();
		return 0;
	}
	int longSpan = 0;
	return (longSpan);
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