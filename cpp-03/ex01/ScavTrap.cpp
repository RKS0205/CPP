#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap Default constructor called\n";
	this->setName("ScavTrap");
	this->setHP(100);
  	this->setEP(50);
  	this->setAD(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap Parameter constructor called\n";
	this->setHP(100);
  	this->setEP(50);
  	this->setAD(20);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called\n";
}

ScavTrap::ScavTrap(ScavTrap const &s) : ClapTrap() {
	std::cout << "ScavTrap Copy constructor called\n";
	*this = s;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &s) {
	std::cout << "ScavTrap Copy assignment operator called\n";
	this->setName(s.getName());
	this->setHP(s.getHP());
	this->setAD(s.getAD());
	this->setEP(s.getEP());
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (this->getHP() == 0)
		std::cout << "ScavTrap " << this->getName() << " cannot attack because"
			<< " he is dead\n";
	else if (this->getEP() == 0)
		std::cout << "ScavTrap " << this->getName() << " cannot attack because"
			<< " he is out of energy\n";
	else {
		std::cout << "ScavTrap " << this->getName() << " attacks " << target
			<< ", causing " << this->getAD() << " points of damage\n";
		this->setEP(this->getEP() - 1);
	}
}

void ScavTrap::guardGate(void) {
	if (this->getHP() == 0)
		std::cout << this->getName() << " cannot guard gate"
		<< " because he is dead\n";
	else
		std::cout << this->getName() << " is now in Gate keeper mode\n";
}
