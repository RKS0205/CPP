#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string type;

	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(std::string const type);
		Animal(const Animal &a);

		Animal &operator=(const Animal &a);

		void setType(std::string type);
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;

};

#endif
