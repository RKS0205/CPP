#include "Bureaucrat.hpp"

int main() {
	Bureaucrat high("High", 1);
	Bureaucrat low("Low", 150);
	Bureaucrat medium("Medium", 75);

	std::cout << std::endl;
	std::cout << high;

	std::cout << "Testing grade too high:\n";
	try {
		high.incrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting grade too low:\n";
	try {
		low.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting functional decrement:\n";
	try {
		medium.decrementGrade();
		std::cout << medium;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting functional increment:\n";
	try {
		medium.incrementGrade();
		std::cout << medium;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
}
