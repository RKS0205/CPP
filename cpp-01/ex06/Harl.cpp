#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void Harl::complain(std::string level) {
	std::string all_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::invalid};

	int	i;

	for (i = 0; i < 4; i++) {
		if (all_levels[i].compare(level) == 0) {
			break ;
		}
	}

	switch (i) {
		case 0 :
			(this->*functions[0])();
			__attribute__((fallthrough));
		case 1 :
			(this->*functions[1])();
			__attribute__((fallthrough));
		case 2 :
			(this->*functions[2])();
			__attribute__((fallthrough));
		case 3 :
			(this->*functions[3])();
			break ;
		case 4 :
			(this->*functions[4])();
			break ;
	}
}

void Harl::debug(void) {
	std::cout << "[DEBUG]" << std::endl << 
	"I love having extra bacon for my " << 
	"7XL-double-cheese-triple-pickle-special-ketchup burger. " <<
	"I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO]" << std::endl <<
	"I cannot believe adding extra bacon costs more money. " <<
	"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[WARNING]" << std::endl << 
	"I think I deserve to have some extra bacon for free. " <<
	"I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR]" << std::endl << 
	"This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::invalid(void) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
