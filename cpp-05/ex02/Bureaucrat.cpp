#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name ("Default"), grade (150) {
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) {
	*this = b;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b) {
	static_cast<std::string>(this->name) = b.getName();
	this->grade = b.getGrade();
	return (*this);
}

const std::string Bureaucrat::getName(void) const {
	return (this->name);
}

int Bureaucrat::getGrade(void) const {
	return (this->grade);
}

void Bureaucrat::incrementGrade(void) {
	if ((this->getGrade() - 1) < 1)
		throw GradeTooHighException();
	else
		this->grade--;
}
void Bureaucrat::decrementGrade(void) {
	if ((this->getGrade() + 1) > 150)
		throw GradeTooLowException();
	else
		this->grade++;
}

void Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << "\n";
	}
	catch (std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << "\n";
	}
}

void Bureaucrat::executeForm(Form const & form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << ".\n";
	}
	catch (const std::exception& e) {
		std::cout << this->getName()
				<< " couldn't execute "
				<< form.getName()
				<< " because "
				<< e.what()
				<< "\n";
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
} 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
} 

std::ostream &operator <<(std::ostream &out, Bureaucrat const &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return (out);
}
