#include "Brain.hpp"
#include <sstream>

Brain::Brain(void) {
	std::cout << "Brain default constructor called\n";
	std::stringstream ss;
	std::string s;

	for (int i = 0; i < 100; i++) {
		ss << i + 1;
		ss >> s;
		ss.clear();
		this->ideas[i] = "Idea " + s;
	}
}

Brain::Brain(const Brain &b) {
	std::cout << "Brain copy constructor called\n";
	*this = b;
}

Brain::~Brain(void) {
 	std::cout << "Brain destructor called\n";
}

Brain &Brain::operator=(const Brain &b) {
	std::cout << "Brain assignment operator called\n";
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = b.getIdea(i);
	}
	return (*this);
}

std::string Brain::getIdea(int i) const {
	return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea) {
	this->ideas[i] = idea;
}
