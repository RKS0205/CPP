#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *brain;

	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(const Cat &c);

		Cat &operator=(const Cat &c);

		void makeSound(void) const;
		Brain *getBrain(void) const;
};

#endif
