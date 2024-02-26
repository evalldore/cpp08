#include <functional>
#include "Span.hpp"

//constructors/destructors
Span::Span(void): _size(0) {}

Span::~Span(void){}

Span::Span(unsigned int size): _size(size) {}

Span::Span(const Span& other): _size(other._size) {
	*this = other;
}

//methods

void Span::addNumber(int num) {
	if (_list.size() >= _size) throw InvalidNumbersException();
	_list.push_back(num);
}

void Span::addNumber(IT& begin, IT& end) {
	if (_list.size() + std::distance(begin, end) > _size) throw InvalidNumbersException();
	_list.insert(_list.end(), begin, end);
}

static void iterList(std::list<int>& list, unsigned int &num, int(*func)(const unsigned int&, const unsigned int&)) {
	unsigned int distAbs;
	std::list<int>::iterator ptr[2];
	for (ptr[0] = list.begin(); ptr[0] != list.end(); ptr[0]++) {
		for (ptr[1] = list.begin(); ptr[1] != list.end(); ptr[1]++) {
			if (ptr[0] == ptr[1]) continue;
			distAbs = (unsigned int)abs(*ptr[0] - *ptr[1]);
			if (func(num, distAbs))
				num = distAbs;
		}
	}
}

static int isGreater(const unsigned int& lhs, const unsigned int& rhs) {
	return (lhs < rhs);
}

static int isLesser(const unsigned int& lhs, const unsigned int& rhs) {
	return (lhs > rhs);
}

unsigned int Span::shortestSpan(void) {
	if (_list.size() < 2) throw InvalidNumbersException();
	unsigned int shortSpan = std::numeric_limits<unsigned int>::max();
	iterList(_list, shortSpan, isLesser);
	if (shortSpan == std::numeric_limits<unsigned int>::max()) throw NoSpanException();
	return shortSpan;
}

unsigned int	Span::longestSpan(void) {
	if (_list.size() < 2) throw InvalidNumbersException();
	unsigned int longSpan = 0;
	iterList(_list, longSpan, isGreater);
	if (longSpan == 0) throw NoSpanException();
	return longSpan;
}

unsigned int	Span::getSize(void) {
	return (_size);
}

//operators

const Span& Span::operator=(const Span& other) {
	if (&other == this) return *this;
	_list.clear();
	_size = other._size;
	_list = other._list;
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
	out << "Size: " << span.getSize() << ' ' << "Shortest: " << span.shortestSpan() << ' ' << "Longest: " << span.longestSpan();
	return out;
}