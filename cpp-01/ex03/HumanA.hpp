#ifndef HUMAN_A_H
# define HUMAN_A_H

#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon &weapon;
	public:
		void	attack(void);
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
};

#endif
