#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void) {
	std::string	input;
	PhoneBook	phonebook;

	while (1) {
		std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
		std::cin >> input;
		if (input == "ADD") {
			phonebook.add();
		}
		else if (input == "SEARCH") {
			phonebook.search();
		}
		else if (input == "EXIT") {
			break ;
		}
		else {
			std::cout << "Invalid option" << std::endl;
		}
	}
}
