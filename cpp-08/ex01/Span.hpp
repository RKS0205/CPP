#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>

class Span {
	private:
		std::vector<int> vect;
		unsigned int max;
	
	public:
		Span(void);
		~Span(void);
		Span(unsigned int n);
		Span(const Span &src);

		Span &operator=(const Span &src);

		unsigned int getMax(void) const;
		const std::vector<int> &getVect(void) const;

		void addNumber(int n);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

		template <typename T>
		void addRange(T begin, T end);

		class NotEnoughCapacity : public std::exception {
			public:
				const char* what(void) const throw();
		};

		class InsufficientElements : public std::exception {
			public:
				const char* what(void) const throw();
		};

};

# include "Span.tpp"

#endif
