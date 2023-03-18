#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
 	const Animal *animals[10];
	// Animal test;

	std::cout << "\nDog constructors:\n";
	std::cout << "--------------------------------\n";
	for (int i = 0; i < 5; i++) {
		animals[i] = new Dog();
	}
	std::cout << "--------------------------------\n";
	std::cout << "\nCat constructors\n";
	std::cout << "--------------------------------\n";
	for (int i = 5; i < 10; i++) {
		animals[i] = new Cat();
	}
	std::cout << "--------------------------------\n";

	std::cout << "\nBrain test: \n\n";
	Cat *cat = new Cat();
	cat->getBrain()->setIdea(0, "idea test");
	Cat *cat2 = new Cat();
	*cat2 = *cat;
	std::cout << "\n";
	std::cout << cat->getBrain()->getIdea(0) << "\n";
	std::cout << cat2->getBrain()->getIdea(0) << "\n";
	std::cout << cat->getBrain()->getIdea(50) << "\n";
	std::cout << cat2->getBrain()->getIdea(50) << "\n";
	std::cout << "\n";
	delete cat;
	delete cat2;

	std::cout << "\nDog destructors:\n";
	std::cout << "--------------------------------\n";
	for (int i = 0; i < 5; i++) {
		delete animals[i];
	}
	std::cout << "--------------------------------\n";
	
	std::cout << "\nCat destructors:\n";
	std::cout << "--------------------------------\n";
	for (int i = 5; i < 10; i++) {
		delete animals[i];
	}
	std::cout << "--------------------------------\n";

	return (0);
}
