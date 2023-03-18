#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain;

	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &d);

		Dog &operator=(const Dog &d);

		void makeSound(void) const;
		Brain *getBrain(void) const;

};

#endif
