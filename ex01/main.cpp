#include <iostream>
#include "Span.hpp"

int main(void) {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	Span sp2 = Span(sp);
	std::cout << sp << std::endl;
	std::cout << sp2 << std::endl;
	return 0;
}