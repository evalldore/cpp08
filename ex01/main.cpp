#include <iostream>
#include "Span.hpp"

#define RESET "\e[0m"
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

static void subject(void) {
	std::cout << YEL << "Subject tests" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void constructors(void) {
	std::cout << YEL << "Constructors tests" << RESET << std::endl;
	std::cout << "Size constructor" << std::endl;
	Span sp = Span(5);
	sp.addNumber(3);
	sp.addNumber(-1);
	sp.addNumber(420);
	sp.addNumber(10);
	sp.addNumber(21);
	std::cout << &sp << "\n\t" << sp << std::endl;
	std::cout << "Copy constructor" << std::endl;
	Span sp2 = Span(sp);
	std::cout << &sp2 << "\n\t" << sp2 << std::endl;
}

static void execeptions(void) {
	std::cout << YEL << "Exceptions tests" << RESET << std::endl;
	std::cout << "Bad amount of numbers" << std::endl;
	Span sp = Span(2);
	sp.addNumber(1);
	try {
		sp.shortestSpan();
	} catch(std::exception &e) {
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	try {
		sp.longestSpan();
	} catch(std::exception &e) {
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	sp.addNumber(10);
	std::cout << "Overflow size" << std::endl;
	try {
		sp.addNumber(3);
	} catch(std::exception &e) {
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	std::cout << "No span" << std::endl;
	Span sp2 = Span(2);
	sp2.addNumber(1);
	sp2.addNumber(1);
	try {
		sp2.longestSpan();
	} catch(std::exception &e) {
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
	try {
		sp2.shortestSpan();
	} catch(std::exception &e) {
		std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
	}
}

int main(void) {
	subject();
	constructors();
	execeptions();
	return 0;
}