#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &a);
		WrongAnimal(std::string const type);

		WrongAnimal &operator=(const WrongAnimal &a);

		void setType(std::string type);
		std::string getType(void) const;
		void makeSound(void) const;

};

#endif
