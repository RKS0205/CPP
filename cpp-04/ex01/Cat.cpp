#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Default Cat constructor called\n";
	this->brain = new Brain();
}

Cat::~Cat(void) {
	delete this->brain;
	std::cout << "Cat destructor called\n";
}

Cat::Cat(const Cat &c) : Animal("Cat") {
	std::cout << "Cat copy constructor called\n";
	this->brain = new Brain(*c.getBrain());
	*this = c;
}

Cat &Cat::operator=(const Cat &c) {
	this->type = c.getType();
	*this->brain = *c.getBrain();
	std::cout << "Cat copy assignment constructor called\n";
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << "Miau\n";
}

Brain* Cat::getBrain(void) const {
	return (this->brain);
}
