#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Default Dog constructor called\n";
	this->brain = new Brain();
}

Dog::~Dog(void) {
	delete this->brain;
	std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog &d) : Animal("Dog") {
	std::cout << "Dog copy constructor called\n";
	this->brain = new Brain(*d.getBrain());
	*this = d;
}

Dog &Dog::operator=(const Dog &d) {
	std::cout << "Dog copy assignment constructor called\n";
	this->type = d.getType();
	*this->brain = *d.getBrain();
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "Woof\n";
}

Brain* Dog::getBrain(void) const {
	return (this->brain);
}
