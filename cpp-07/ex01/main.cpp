#include "iter.hpp"
#include <iostream>

int main(void) {
	char c[5] = {'a', 'b', 'c', 'd', 'e'};
	int i[5] = {1, 2, 3, 4, 5};

	iter(c, 5, print);
	std::cout << "\n";
	iter(i, 5, print);
}
