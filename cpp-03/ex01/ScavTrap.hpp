#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const &s);
		ScavTrap &operator=(ScavTrap const &s);

		void attack(const std::string &target);
  		void guardGate(void);
};

#endif
