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
	if (_list.size() < 2)
		throw InvalidNumbersException();
	unsigned int shortSpan = std::numeric_limits<unsigned int>::max();
	unsigned int distAbs;
	std::list<int>::iterator ptr[2];
	for (ptr[0] = _list.begin(); ptr[0] != _list.end(); ptr[0]++) {
		for (ptr[1] = _list.begin(); ptr[1] != _list.end(); ptr[1]++) {
			if (ptr[0] == ptr[1]) continue;
			distAbs = (unsigned int)abs(*ptr[0] - *ptr[1]);
			if (distAbs < shortSpan)
				shortSpan = distAbs;
		}
	}
	if (shortSpan == std::numeric_limits<unsigned int>::max())
		throw NoSpanException();
	return shortSpan;
}

unsigned int	Span::longestSpan(void) {
	if (_list.size() < 2)
		throw InvalidNumbersException();
	unsigned int longSpan = 0;
	unsigned int distAbs;
	std::list<int>::iterator ptr[2];
	for (ptr[0] = _list.begin(); ptr[0] != _list.end(); ptr[0]++) {
		for (ptr[1] = _list.begin(); ptr[1] != _list.end(); ptr[1]++) {
			if (ptr[0] == ptr[1]) continue;
			distAbs = (unsigned int)abs(*ptr[0] - *ptr[1]);
			if (distAbs > longSpan)
				longSpan = distAbs;
		}
	}
	if (longSpan == 0)
		throw NoSpanException();
	return longSpan;
}

//operators

const Span& Span::operator=(const Span& other) {
	(void)other;
	return *this;
}

//exceptions

const char* Span::InvalidNumbersException::what(void) const throw() {
	return "Invalid amount of numbers";
}

const char* Span::NoSpanException::what(void) const throw() {
	return "No span in the list";
}

//ostream

std::ostream& operator<<(std::ostream& out, Span& span) {
	out << "Shortest: " << span.shortestSpan() << ' ' << "Longest: " << span.longestSpan();
	return out;
}