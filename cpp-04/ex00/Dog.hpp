#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &a);

		Dog &operator=(const Dog &a);

		void makeSound(void) const;

};

#endif
