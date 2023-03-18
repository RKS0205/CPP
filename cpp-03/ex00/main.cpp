#include "ClapTrap.hpp"

int main(void) {
	ClapTrap temp;
	ClapTrap clap1(temp);
	ClapTrap clap2("clap2");

	clap1.setAD(1);
	clap2.setAD(1);

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAD());
	clap2.beRepaired(1);
	std::cout << "\n";

	clap1.setAD(10);
	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getAD());
	clap2.beRepaired(1);
	std::cout << "\n";

	for (int i = 0; i < 8; i++) {
		clap1.beRepaired(1);
	}

	std::cout << "\n";

	clap1.attack(clap2.getName());
	clap1.beRepaired(1);
	clap2.takeDamage(clap1.getAD());
	clap2.attack(clap1.getName());
	clap2.beRepaired(10);

	std::cout << "\n";

	return (0);
}
