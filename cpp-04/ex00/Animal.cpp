#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
	std::cout << "Default Animal constructor called\n";
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called\n";
}

Animal::Animal(std::string const type) {
	std::cout << "Animal constructor called for " << type << " \n";
	this->setType(type);
}

Animal::Animal(const Animal &a) {
	std::cout << "Animal copy constructor called\n";
	*this = a;
}

Animal &Animal::operator=(const Animal &a) {
	this->type = a.getType();
	std::cout << "Animal copy assignment constructor called\n";
	return (*this);
}

void Animal::setType(std::string type) {
	this->type = type;
}

std::string Animal::getType(void) const {
	return (this->type);
}

void Animal::makeSound(void) const {
	std::cout << "Animal sound\n";
}
