#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		const	std::string &getType();
		void	setType(std::string new_type);
};

#endif
