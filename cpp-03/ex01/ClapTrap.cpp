#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap Parameter constructor called\n";
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called\n";
}

ClapTrap::ClapTrap(ClapTrap const &c) {
	std::cout << "ClapTrap Copy constructor called\n";
	*this = c;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &c) {
	std::cout << "ClapTrap Copy assignment operator called\n";
	this->setName(c.getName());
	this->setHP(c.getHP());
	this->setAD(c.getAD());
	this->setEP(c.getEP());
	return (*this);
}

std::string ClapTrap::getName(void) const {
	return (this->name);
}

int ClapTrap::getHP(void) const {
	return (this->hitPoints);
}

int ClapTrap::getEP(void) const {
	return (this->energyPoints);
}

int ClapTrap::getAD(void) const {
	return (this->attackDamage);
}

void ClapTrap::setName(std::string name) {
	this->name = name;
}

void ClapTrap::setHP(int hp) {
	this->hitPoints = hp;
}

void ClapTrap::setEP(int ep) {
	this->energyPoints = ep;
}

void ClapTrap::setAD(int ad) {
	this->attackDamage = ad;
}

void ClapTrap::attack(const std::string& target) {
	if (this->getHP() == 0)
		std::cout << this->getName() << " cannot attack because"
			<< " he is dead\n";
	else if (this->getEP() == 0)
		std::cout << this->getName() << " cannot attack because"
			<< " he is out of energy\n";
	else {
		std::cout << this->getName() << " attacks " << target
			<< ", causing " << this->getAD() << " points of damage\n";
		this->setEP(this->getEP() - 1);
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHP() == 0)
		std::cout << this->getName() << " cannot take damage"
		<< " he is dead\n";
	else {
		std::cout << this->getName() << " takes "
			<< amount << " damage\n";
		this->setHP(this->getHP() - amount);
		if (this->getHP() <= 0) {
			this->setHP(0);
			std::cout << this->getName() << " has died\n";
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getHP() == 0)
		std::cout << this->getName() << " cannot repair because"
			<< " he is dead\n";
	else if (this->getEP() == 0)
		std::cout << this->getName() << " cannot repair because"
			<< " he is out of energy\n";
	else {
		std::cout << this->getName() << " repairs himself, recovering "
			<< amount << " HP\n";
		this->setHP(this->getHP() + amount);
		this->setEP(this->getEP() - 1);
	}
}
