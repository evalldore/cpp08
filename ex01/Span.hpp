#pragma once
#include <exception>
#include <list>
#include <iostream>
#include <limits>
#include <cstdlib>
class Span {
	private:
		typedef std::list<int>::iterator IT;
		std::list<int>		_list;
		unsigned int		_size;

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
		void			addNumber(int);
		void			addNumber(IT&, IT&);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		unsigned int	getSize(void);
		
		//operators
		const Span& operator=(const Span& other);
};

std::ostream& operator<<(std::ostream&, Span&);