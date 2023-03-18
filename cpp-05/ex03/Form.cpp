#include "Form.hpp"

Form::Form(void) : name ("Default"), isSigned(false), gradeSign(150), gradeExec(150) {
}

Form::~Form(void) {
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec) {
	if (this->getGradeExec() < 1 || this->getGradeSign() < 1) {
    	throw GradeTooHighException();
	}
	if (this->getGradeExec() > 150 || this->getGradeSign() > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form &f) : name("Default"), isSigned(false), gradeSign(150), gradeExec(150) {
	*this = f;
	if (f.getGradeExec() < 1 || f.getGradeSign() < 1) {
    	throw GradeTooHighException();
	}
	if (f.getGradeExec() > 150 || f.getGradeSign() > 150) {
		throw GradeTooLowException();
	}
}

Form& Form::operator=(const Form &f) {
	static_cast<std::string>(this->name) = f.getName();
	this->setTarget(f.getTarget());
	const_cast<int&>(this->gradeExec) = f.getGradeExec();
	const_cast<int&>(this->gradeSign) = f.getGradeSign();
	this->isSigned = f.getIsSigned();
	return (*this);
}

const std::string Form::getName(void) const {
	return (this->name);
}

int Form::getGradeExec(void) const {
	return (this->gradeExec);
}

int Form::getGradeSign(void) const {
	return (this->gradeSign);
}

bool Form::getIsSigned(void) const {
	return (this->isSigned);
}

const std::string Form::getTarget(void) const {
	return (this->target);
}

void Form::setTarget(std::string target) {
	const_cast<std::string&>(this->target) = target;
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= this->getGradeSign()) {
		this->isSigned = true;
	}
	else {
		throw GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
} 

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* Form::UnsignedFormException::what() const throw() {
	return "Form hasn't been signed!";
} 

std::ostream &operator <<(std::ostream &out, Form const &f) {
	out << "Form: " << f.getName() << "\n";
	if (f.getIsSigned()) {
		out << "Signed: True\n";
	}
	else {
		out << "Signed: False\n";
	}
	out << "Grade required to sign: " << f.getGradeSign() << "\n";
	out << "Grade required to execute: " << f.getGradeExec() << "\n";
	return (out);
}
