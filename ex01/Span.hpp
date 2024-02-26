#pragma once
#include <exception>
#include <list>
#include <iostream>
#include <limits>
#include <cstdlib>
class Span {
	private:
		std::list<int>		_list;
		const unsigned int	_size;

		Span(void);
	public:
		//execeptions
		class InvalidNumbersException : public std::exception {
			virtual const char* what(void) const throw();
		};
		class NoSpanException : public std::exception {
			virtual const char* what(void) const throw();
		};
		//constructors/destructors
		Span(unsigned int size);
		Span(const Span& other);
		~Span(void);

		//methods
		void			addNumber(int num);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		
		//operators
		const Span& operator=(const Span& other);
};

std::ostream& operator<<(std::ostream&, Span&);