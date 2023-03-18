#include "Data.hpp"

Data::Data(void) : input("Default") {
}

Data::~Data(void) {
}

Data::Data(const std::string input) : input(input) {
}

Data::Data(const Data &d) {
	*this = d;
}

Data& Data::operator=(const Data &d) {
	this->input = d.input;
	return (*this);
}

std::string Data::getInput(void) {
	return (this->input);
}
