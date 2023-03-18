#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
	  	Intern(void);
		Intern(const Intern &i);
		~Intern(void);

		Intern &operator=(const Intern &i);

		Form* createShrubberyForm(const std::string target) const;
		Form* createRobotomyForm(const std::string target) const;
		Form* createPresidentialForm(const std::string target) const;
		Form* makeForm(const std::string name, const std::string target);

		class InvalidFormException : public std::exception {
			public:
				const char* what(void) const throw();
  		};
};

#endif
