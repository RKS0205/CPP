#include <iostream>
#include <list>
#include <vector>

#include "Span.hpp"

int main()
{
	Span sp1 = Span(5);

	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);

	std::cout << "Testing normal span:\n";

	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

	Span sp2 = Span(50000);

	std::cout << "\nTesting span with 50k numbers:\n";
	std::list<int> test(50000, 0);
  	sp2.addRange(test.begin(), test.end());
	std::cout << "Span size: " << sp2.getVect().size() << "\n";

	Span sp3 = Span(1);

	sp3.addNumber(1);
	std::cout << "\nTesting not enough capacity exception:\n";
	try {
		sp3.addNumber(2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "\nTesting insufficient elements exception:\n";
	try {
		sp3.shortestSpan();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

}
