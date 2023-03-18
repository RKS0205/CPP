#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int		size;
		int		index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add(void);
		void search(void);
		void showInfo(Contact contact, int i);
		void showContact(Contact contact);
};

#endif
