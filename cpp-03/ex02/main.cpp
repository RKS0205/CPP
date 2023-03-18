#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap clap("Clap");
	FragTrap frag("Frag");

	std::cout << "\n";

	clap.setAD(1);
	clap.attack(frag.getName());
	frag.takeDamage(clap.getAD());
	frag.attack(clap.getName());
	clap.takeDamage(frag.getAD());
	frag.highFivesGuys();
	frag.beRepaired(1);
	std::cout << "\n";

	frag.takeDamage(100);
	frag.attack(clap.getName());
	frag.highFivesGuys();
	frag.beRepaired(1);
	std::cout << "\n";

	return (0);
}
