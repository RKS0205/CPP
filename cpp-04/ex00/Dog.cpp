#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Default Dog constructor called\n";
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog &a) : Animal("Dog") {
	std::cout << "Dog copy constructor called\n";
	*this = a;
}

Dog &Dog::operator=(const Dog &a) {
	this->type = a.getType();
	std::cout << "Dog copy assignment constructor called\n";
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "Woof\n";
}
