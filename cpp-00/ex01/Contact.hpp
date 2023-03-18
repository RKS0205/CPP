#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {
	private:
		std::string	phone_number;
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string	secret;
		
	public:
		void	setPhoneNumber(std::string s);
		void	setFirstName(std::string s);
		void	setLastName(std::string s);
		void	setNickname(std::string s);
		void	setSecret(std::string s);

		std::string	getPhoneNumber(void);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getSecret(void);

};

#endif
