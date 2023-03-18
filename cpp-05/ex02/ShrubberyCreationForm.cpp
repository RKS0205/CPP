#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("Shrubbery Creation Form", 145, 137) {
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : Form(s) {
	*this = s;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s) {
	(void)s;
 	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const {
	if (this->getIsSigned() == false) {
		throw Form::UnsignedFormException();
	}
	else if (executor.getGrade() > this->getGradeExec()) {
		throw Form::GradeTooLowException();
	}
	else {
		std::ofstream outfile (this->getTarget().c_str());   
		std::string tree =
		"	   _-_        \n"
		"    /~~   ~~\\     \n"
		" /~~         ~~\\  \n" 
		"{               } \n"
		" \\  _-     -_  /  \n"
		"   ~  \\\\ //  ~    \n"
		"_- -   | | _- _   \n"
		"  _ -  | |   -_   \n"
		"      // \\\\       \n";
		outfile << tree;
		outfile.close();
	}

}
