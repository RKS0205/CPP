#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat *b;
	Form *f;

	std::cout << "\nTesting form grade too high:\n";
	try {
		f = new Form("Form", 0, 1);
		std::cout << *f;
		delete f;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting form grade too low:\n";
	try {
		f = new Form("Form", 151, 1);
		std::cout << *f;
		delete f;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting grade too low to sign:\n";
	try {
		b = new Bureaucrat("Test", 2);
		f = new Form("Form", 1, 1);
		std::cout << *f << "\n";
		std::cout << *b;
		b->signForm(*f);
		delete b;
		delete f;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting bureaucrat allowed to sign:\n\n";

	try {
		b = new Bureaucrat("Test", 1);
		f = new Form("Form", 1, 1);
		std::cout << *f;
		std::cout << "\n";
		std::cout << *b;
		std::cout << "\n";
		b->signForm(*f);
		std::cout << "\n";
		std::cout << *f;
		delete b;
		delete f;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

  return (0);
}
