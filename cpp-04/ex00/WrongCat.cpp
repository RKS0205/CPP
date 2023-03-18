#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat constructor called\n";
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(const WrongCat &a) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat copy constructor called\n";
	*this = a;
}

WrongCat &WrongCat::operator=(const WrongCat &a) {
	this->type = a.getType();
	std::cout << "WrongCat copy assignment constructor called\n";
	return (*this);
}

void WrongCat::makeSound(void) const {
	std::cout << "Miau\n";
}
