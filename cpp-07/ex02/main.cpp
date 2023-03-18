#include "Array.hpp"
#include <iostream>

int main(void) {
	Array<int> a(5);
	Array<char> b(5);

	for (unsigned int i = 0; i < 5; i++) {
		a[i] = i + 1;
	}
	for (int i = 0; i < 5; i++) {
		b[i] = i + 'a';
	}
	std::cout << "Testing int array:\n";
	std::cout << "Size of int array is " << a.size() << "\n";
	std::cout << a[0] << "\n";
	std::cout << a[1] << "\n";
	std::cout << a[2] << "\n";
	std::cout << a[3] << "\n";
	std::cout << a[4] << "\n\n";

	std::cout << "Testing char array:\n";
	std::cout << "Size of char array is " << a.size() << "\n";
	std::cout << b[0] << "\n";
	std::cout << b[1] << "\n";
	std::cout << b[2] << "\n";
	std::cout << b[3] << "\n";
	std::cout << b[4] << "\n\n";

	Array<char> c(b);
	std::cout << "Testing copy constructor:\n";
	std::cout << c[0] << "\n";
	std::cout << c[1] << "\n";
	std::cout << c[2] << "\n";
	std::cout << c[3] << "\n";
	std::cout << c[4] << "\n\n";

	Array<char> d;
	d = b;
	d = c;
	std::cout << "Testing assignment operator:\n";
	std::cout << d[0] << "\n";
	std::cout << d[1] << "\n";
	std::cout << d[2] << "\n";
	std::cout << d[3] << "\n";
	std::cout << d[4] << "\n\n";
	try {
		std::cout << a[-1];
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	try {
		std::cout << a[6];
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
}
