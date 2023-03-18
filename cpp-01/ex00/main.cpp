#include "Zombie.hpp"

int main(void) {
	Zombie *tester;
	
	tester = newZombie("tester_zombie");
	tester->announce();
	delete tester;
	randomChump("randomChump_tester");
}
