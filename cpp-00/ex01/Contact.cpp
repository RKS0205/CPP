#include "Contact.hpp"

void	Contact::setFirstName(std::string s) {
	this->first_name = s;
}

void	Contact::setLastName(std::string s) {
	this->last_name = s;
}

void	Contact::setPhoneNumber(std::string s) {
	this->phone_number = s;
}

void	Contact::setNickname(std::string s) {
	this->nickname = s;
}

void	Contact::setSecret(std::string s) {
	this->secret = s;
}

std::string	Contact::getFirstName(void) {
	return (this->first_name);
}

std::string	Contact::getLastName(void) {
	return (this->last_name);
}

std::string	Contact::getNickname(void) {
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void) {
	return (this->phone_number);
}

std::string	Contact::getSecret(void) {
	return (this->secret);
}
