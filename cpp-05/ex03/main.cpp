#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat *b;
	Intern i;
	Form *f;

	std::cout << "\nTesting intern creating shrubbery form:\n";

	try {
		b = new Bureaucrat("Test", 1);
		f = i.makeForm("shrubbery creation", "ShrubTest");
		b->signForm(*f);
		std::cout << *f;
		b->executeForm(*f);
		delete b;
		delete f;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting intern creating robotomy form:\n";

	try {
		b = new Bureaucrat("Test", 1);
		f = i.makeForm("robotomy request", "RoboTest");
		b->signForm(*f);
		std::cout << *f;
		b->executeForm(*f);
		delete b;
		delete f;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting intern creating presidential form:\n";

	try {
		b = new Bureaucrat("Test", 1);
		f = i.makeForm("presidential pardon", "PresTest");
		b->signForm(*f);
		std::cout << *f;
		b->executeForm(*f);
		delete b;
		delete f;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting intern creating invalid form:\n";

	try {
		b = new Bureaucrat("Test", 150);
		f = i.makeForm("invalid form", "InvalidTest");
		b->signForm(*f);
		std::cout << *f;
		b->executeForm(*f);
		delete b;
		delete f;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		delete b;
	}

	std::cout << "\n";

	return (0);
}
