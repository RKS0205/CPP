#include "Intern.hpp"

Intern::Intern(void) {
}

Intern::~Intern(void) {
}

Intern::Intern(const Intern &i) {
	*this = i;
}

Intern& Intern::operator=(const Intern &i) {
	(void)i;
 	return (*this);
}

Form* Intern::createShrubberyForm(const std::string target) const {
	return (new ShrubberyCreationForm(target));
}

Form* Intern::createRobotomyForm(const std::string target) const {
	return (new RobotomyRequestForm(target));
}

Form* Intern::createPresidentialForm(const std::string target) const {
  	return (new PresidentialPardonForm(target));
}

Form* Intern::makeForm(const std::string name, const std::string target) {
	std::string formType[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (Intern::*f[3])(const std::string) const = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm};

	for (int i = 0; i < 3; i++) {
		if (formType[i].compare(name) == 0) {
			std::cout << "Intern creates " << formType[i] << "\n";
			return ((this->*f[i])(target));
		}
	}

	throw InvalidFormException();
	return (NULL);
}

const char* Intern::InvalidFormException::what(void) const throw() {
  return ("Invalid form!");
}
