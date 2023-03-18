#include "PhoneBook.hpp"
#include <iomanip>
#include <string>
#include <sstream>

PhoneBook::PhoneBook(void) {
	this->index = 0;
	this->size = 0;
}

PhoneBook::~PhoneBook(void) {
}

void	PhoneBook::showInfo(Contact contact, int i) {
	Contact	temp = contact;

	if (temp.getFirstName().length() > 10) {
		temp.setFirstName(temp.getFirstName().substr(0, 9) + '.');
	}
	if (temp.getLastName().length() > 10) {
		temp.setLastName(temp.getLastName().substr(0, 9) + '.');
	}
	if (temp.getNickname().length() > 10) {
		temp.setNickname(temp.getNickname().substr(0, 9) + '.');
	}
	if (temp.getPhoneNumber().length() > 10) {
		temp.setPhoneNumber(temp.getPhoneNumber().substr(0, 9) + '.');
	}
	if (temp.getSecret().length() > 10) {
		temp.setSecret(temp.getSecret().substr(0, 9) + '.');
	}
	std::cout << "|" << std::setw(10) << i;
	std::cout << "|" << std::setw(10) << temp.getFirstName();
	std::cout << "|" << std::setw(10) << temp.getLastName();
	std::cout << "|" << std::setw(10) << temp.getNickname() << "|" << std::endl;
}

void	PhoneBook::showContact(Contact contact) {
	std::cout << "First name : " << contact.getFirstName() << std::endl;
	std::cout << "Last name : " << contact.getLastName() << std::endl;
	std::cout << "Nickname : " << contact.getNickname() << std::endl;
	std::cout << "Phone number : " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << contact.getSecret() << std::endl << std::endl;
}

void	PhoneBook::add(void) {
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;

	std::cin.ignore();
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	if (first_name == "") {
		std::cout << "Invalid input" << std::endl << std::endl;
		return ;
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	if (last_name == "") {
		std::cout << "Invalid input" << std::endl << std::endl;
		return ;
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	if (nickname == "") {
		std::cout << "Invalid input" << std::endl << std::endl;
		return ;
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	if (phone_number == "" || phone_number.find_first_not_of("0123456789") != std::string::npos) {
		std::cout << "Invalid input" << std::endl << std::endl;
		return ;
	}
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, secret);
	if (secret == "") {
		std::cout << "Invalid input" << std::endl << std::endl;
		return ;
	}
	this->contacts[this->index].setFirstName(first_name);
	this->contacts[this->index].setLastName(last_name);
	this->contacts[this->index].setNickname(nickname);
	this->contacts[this->index].setPhoneNumber(phone_number);
	this->contacts[this->index].setSecret(secret);
	this->index++;
	if (this->size < 8)
		this->size++;
	if (this->index == 8)
		this->index = 0;
	return ;
}

void	PhoneBook::search(void) {
	std::string	input;
	std::stringstream temp;
	int	index = -1;

	std::cout << std::endl;
	std::cout << "|   Index  |";
	std::cout << "First Name|";
	std::cout << " Last Name|";
	std::cout << " Nickname |" << std::endl;
	for (int i = 0; i < this->size; i++) {
		this->showInfo(this->contacts[i], i);
	}
	std::cout << std::endl;
	if (this->size == 0)
		return ;
	std::cout << "Enter index : ";
	std::cin >> input;
	temp << input;
	temp >> index;
	if (!temp.fail() && index < this->size && index >= 0) {
		std::cout << std::endl;
		this->showContact(contacts[index]);
	}
	else {
		std::cout << "Invalid index" << std::endl;
	}
}
