#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");

	std::cout << "\n";

	clap.setAD(1);
	clap.attack(scav.getName());
	scav.takeDamage(clap.getAD());
	scav.attack(clap.getName());
	clap.takeDamage(scav.getAD());
	scav.guardGate();
	scav.beRepaired(1);
	std::cout << "\n";

	scav.takeDamage(100);
	scav.attack(clap.getName());
	scav.guardGate();
	scav.beRepaired(1);
	std::cout << "\n";

	return (0);
}
