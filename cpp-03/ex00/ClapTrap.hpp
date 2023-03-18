#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	private:
		std::string name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &c);
		~ClapTrap(void);
		ClapTrap &operator=(ClapTrap const &c);
		std::string getName(void) const;
		int getHP(void) const;
		int getEP(void) const;
		int getAD(void) const;
		void setName(std::string name);
		void setHP(int hp);
		void setEP(int ep);
		void setAD(int ad);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
