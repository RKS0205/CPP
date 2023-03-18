#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeSign;
		const int gradeExec;

	protected:
		const std::string target;

	public:
		Form(void);
		virtual ~Form(void);
		Form(const std::string name, const int gradeSign, const int gradeExec);
		Form(const Form &f);

		Form& operator=(const Form &f);

		const std::string getName(void) const;
		int getGradeSign(void) const;
		int getGradeExec(void) const;
		bool getIsSigned(void) const;
		const std::string getTarget(void) const;
		void setTarget(std::string target);

		void beSigned(Bureaucrat &b);
		virtual void execute(const Bureaucrat &b) const = 0;

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class UnsignedFormException: public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream &operator <<(std::ostream &out, Form const &f);

#endif
