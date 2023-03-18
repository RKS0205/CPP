#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "Default WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(std::string const type) {
	std::cout << "WrongAnimal constructor called for " << type << " \n";
	this->setType(type);
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) {
	std::cout << "WrongAnimal copy constructor called\n";
	*this = a;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a) {
	this->type = a.getType();
	std::cout << "WrongAnimal copy assignment constructor called\n";
	return (*this);
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}

std::string WrongAnimal::getType(void) const {
	return (this->type);
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal sound\n";
}
