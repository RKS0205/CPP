#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat *b;
	Form *f;

	std::cout << "\nShrubbery Form Test:\n";

	try {
		b = new Bureaucrat("Test", 1);
		f = new ShrubberyCreationForm("ShrubTest");
		b->signForm(*f);
		std::cout << *f;
		b->executeForm(*f);
		delete b;
		delete f;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nRobotomy Form Test:\n";

	try {
		b = new Bureaucrat("Test", 1);
		f = new RobotomyRequestForm("RobotTest");
		b->signForm(*f);
		std::cout << *f;
		b->executeForm(*f);
		delete b;
		delete f;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nPresidential Form Test:\n";

	try {
		b = new Bureaucrat("Test", 1);
		f = new PresidentialPardonForm("PresTest");
		b->signForm(*f);
		std::cout << *f;
		b->executeForm(*f);
		delete b;
		delete f;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nGrade too low to sign test:\n";

	try {
		b = new Bureaucrat("Test", 150);
		f = new PresidentialPardonForm("PresTest");
		b->signForm(*f);
		b->executeForm(*f);
		delete b;
		delete f;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nGrade too low to execute test:\n";

	try {
		b = new Bureaucrat("Test", 20);
		f = new PresidentialPardonForm("PresTest");
		std::cout << *b;
		b->signForm(*f);
		b->executeForm(*f);
		delete b;
		delete f;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	return (0);
}
