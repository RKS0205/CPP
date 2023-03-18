#include "easyfind.hpp"

int main(void) {
	std::vector<int> v_test;
	std::list<int> l_test;

	for (int i = 0; i < 10; i++) {
		v_test.insert(v_test.begin(), i + 1);
	}
	for (int i = 0; i < 10; i++) {
		l_test.insert(l_test.begin(), i + 1);
	}

	std::cout << "-----Test with valid numbers-----\n";

	std::vector<int>::iterator it1 = easyfind(v_test, 1);
	std::cout << "Number found in vector : " << *it1 << "\n";
	
	std::list<int>::iterator it2 = easyfind(l_test, 1);
	std::cout << "Number found in list : " << *it2 << "\n";

	it1 = easyfind(v_test, 10);
	std::cout << "Number found in vector : " << *it1 << "\n";
	
	it2 = easyfind(l_test, 10);
	std::cout << "Number found in list : " << *it2 << "\n";

	std::cout << "\n-----Test with invalid numbers-----\n";
	try {
		std::vector<int>::iterator it1 = easyfind(v_test, 11);
		std::cout << *it1 << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::list<int>::iterator it2 = easyfind(l_test, 11);
		std::cout << *it2 << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::vector<int>::iterator it1 = easyfind(v_test, -1);
		std::cout << *it1 << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::list<int>::iterator it2 = easyfind(l_test, -1);
		std::cout << *it2 << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}


	return (0);
}
