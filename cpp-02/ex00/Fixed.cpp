#include "Fixed.hpp"

int const Fixed::fractional_bits = 8;

Fixed::Fixed(void) {
	this->rawBits  = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator = (Fixed const &fixed) {
	std::cout << "Copy assignment operator called\n";
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->rawBits);
}

void Fixed::setRawBits(int const bits) {
	this->rawBits = bits;
}
