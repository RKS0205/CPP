#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap Default constructor called\n";
	this->setName("FragTrap");
	this->setHP(100);
  	this->setEP(100);
  	this->setAD(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Parameter constructor called\n";
	this->setHP(100);
  	this->setEP(100);
  	this->setAD(30);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called\n";
}

FragTrap::FragTrap(FragTrap const &s) : ClapTrap() {
	std::cout << "FragTrap Copy constructor called\n";
	*this = s;
}

FragTrap &FragTrap::operator=(FragTrap const &s) {
	std::cout << "FragTrap Copy assignment operator called\n";
	this->setName(s.getName());
	this->setHP(s.getHP());
	this->setAD(s.getAD());
	this->setEP(s.getEP());
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	if (this->getHP() == 0)
		std::cout << this->getName() << " cannot high five"
		<< " because he is dead\n";
	else
		std::cout << this->getName() << " high fives someone\n";
}
