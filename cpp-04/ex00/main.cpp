#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* test = new WrongAnimal();
	const WrongAnimal* test2 = new WrongCat();

	std::cout << "\n";

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << test2->getType() << " \n" << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	test->makeSound();
	test2->makeSound();

	std::cout << "\n";

	delete i;
	delete j;
	delete meta;
	delete test;
	delete test2;

	return 0;
}
