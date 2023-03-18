#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form() {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("Presidential Pardon Form", 25, 5) {
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form(p) {
	*this = p;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &p) {
	(void)p;
 	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const {
	if (this->getIsSigned() == false) {
		throw Form::UnsignedFormException();
	}
	else if (executor.getGrade() > this->getGradeExec()) {
		throw Form::GradeTooLowException();
	}
	else {
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
	}

}
