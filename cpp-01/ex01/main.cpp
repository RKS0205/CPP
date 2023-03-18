#include "Zombie.hpp"

int main(void) {
	Zombie *tester;

	tester = zombieHorde(10, "horde_tester");
	for (int i = 0; i < 10; i++) {
		tester[i].announce();
	}
	delete[] tester;
}
