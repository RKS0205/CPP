#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form() {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("Robotomy Request Form", 72, 45) {
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : Form(r) {
	*this = r;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &r) {
	(void)r;
 	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const {
	if (this->getIsSigned() == false) {
		throw Form::UnsignedFormException();
	}
	else if (executor.getGrade() > this->getGradeExec()) {
		throw Form::GradeTooLowException();
	}
	else {
		unsigned int seed;
 		int randomizer = rand_r(&seed) % (10);
		if (randomizer > 4) {
			std::cout << "Bzzzz, " << this->getTarget() << " has been robotomized!\n"; 
		}
		else {
			std::cout << "Bzzzz, Robotomization has failed!\n";	
		}
	}

}
