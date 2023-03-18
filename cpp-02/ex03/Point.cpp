#include "Point.hpp"

Point::Point(void) {
	const_cast<Fixed &>(this->x) = 0;
	const_cast<Fixed &>(this->y) = 0;
}

Point::Point(float const x, float const y) {
	const_cast<Fixed &>(this->x) = x;
	const_cast<Fixed &>(this->y) = y;
}

Point::Point(Point const &p) {
	*this = p;
}

Point::~Point(void) {
}

Point &Point::operator=(const Point &p) {
	const_cast<Fixed  &>(this->x) = p.getX();
	const_cast<Fixed  &>(this->y) = p.getY();
	return (*this);
}

Fixed const Point::getX(void) const {
	return (this->x);
}

Fixed const Point::getY(void) const {
	return (this->y);
}

void	Point::setX(Fixed const x) {
	const_cast<Fixed &> (this->x) = x;
}

void	Point::setY(Fixed const y) {
	const_cast<Fixed &> (this->y) = y;
}
