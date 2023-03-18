#include "Fixed.hpp"
#include <cmath>

int const Fixed::fractional_bits = 8;

Fixed::Fixed(void) : rawBits(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called\n";
	this->rawBits = num << fractional_bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	this->rawBits = static_cast<int>(roundf(num * (1 << this->fractional_bits)));
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

float Fixed::toFloat(void) const {
	return (static_cast <float>(this->rawBits) / (1 << this->fractional_bits));
}

int Fixed::toInt(void) const {
	return (this->rawBits >> this->fractional_bits);
}

std::ostream &operator <<(std::ostream &out, Fixed const &f) {
	out << f.toFloat();
	return (out);
}

bool Fixed::operator< (Fixed const &fixed) const {
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator> (Fixed const &fixed) const {
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator>=(Fixed const &fixed) const {
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(Fixed const &fixed) const {
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(Fixed const &fixed) const {
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(Fixed const &fixed) const {
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(Fixed const &fixed) const {
	Fixed ret = (this->toFloat() + fixed.toFloat());
	return (ret);
}

Fixed Fixed::operator-(Fixed const &fixed) const {
	Fixed ret = (this->toFloat() - fixed.toFloat());
	return (ret);
}

Fixed Fixed::operator*(Fixed const &fixed) const {
	Fixed ret = (this->toFloat() * fixed.toFloat());
	return (ret);
}

Fixed Fixed::operator/(Fixed const &fixed) const {
	Fixed ret = (this->toFloat() / fixed.toFloat());
	return (ret);
}

Fixed &Fixed::operator++(void) {
	++this->rawBits;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->rawBits++;
	return (temp);
}

Fixed &Fixed::operator--(void) {
	--this->rawBits;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->rawBits--;
	return (temp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(Fixed const &f1, Fixed const &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(Fixed const &f1, Fixed const &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}
