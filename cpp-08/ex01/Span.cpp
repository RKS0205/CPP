#include "Span.hpp"

Span::Span(void) : vect(std::vector<int>()), max(0) {
}

Span::~Span(void) {
}

Span::Span(unsigned int n) : vect(std::vector<int>()), max(n) {
}

Span::Span(const Span &src) : vect(std::vector<int>()), max(0) {
	*this = src;
}

Span &Span::operator=(const Span &src) {
	this->vect = std::vector<int>(src.getVect());
	this->max = src.getMax();
	return (*this);
}

const std::vector<int> &Span::getVect(void) const {
	return (this->vect);
}

unsigned int Span::getMax(void) const {
	return (this->max);
}

void Span::addNumber(int n) {
	if (this->vect.size() == this->max)
		throw NotEnoughCapacity();
	else
		this->vect.push_back(n);
}

unsigned int Span::shortestSpan(void) {
	std::vector<int> copy(this->vect);
	std::vector<int>::iterator it;
	int diff;

	if (this->vect.size() < 2)
		throw InsufficientElements();
	std::sort(copy.begin(), copy.end());
	diff = 0;
	for (it = copy.begin() + 1; it != copy.end(); it++) {
		if (abs(*it - *(it - 1)) < diff || diff == 0)
			diff = abs(*it - *(it - 1));
	}
	return (diff);
}

unsigned int Span::longestSpan(void) {
	if (this->vect.size() < 2)
		throw InsufficientElements();
	std::vector<int>::iterator it1 = std::min_element(this->vect.begin(), this->vect.end());
  	std::vector<int>::iterator it2 = std::max_element(this->vect.begin(), this->vect.end());
  	return (*it2 - *it1);
}

const char* Span::NotEnoughCapacity::what(void) const throw() {
  	return ("Not enough capacity");
}

const char* Span::InsufficientElements::what(void) const throw() {
  	return ("Insufficient elements");
}
