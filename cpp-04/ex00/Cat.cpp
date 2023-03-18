#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Default Cat constructor called\n";
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called\n";
}

Cat::Cat(const Cat &a) : Animal("Cat") {
	std::cout << "Cat copy constructor called\n";
	*this = a;
}

Cat &Cat::operator=(const Cat &a) {
	this->type = a.getType();
	std::cout << "Cat copy assignment constructor called\n";
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << "Miau\n";
}
