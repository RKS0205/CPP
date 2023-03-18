#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

Base* generate(void) {
	srand((unsigned) time(0));
  	int randomizer = (rand() % 3);

	switch (randomizer) {
		case 0:
			return (new A());
			break;
		case 1:
			return (new B());
			break;
		case 2:
			return (new C());
			break;
	}
	return (NULL);
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "Type: A\n";
  else if (dynamic_cast<B*>(p))
    std::cout << "Type: B\n";
  else if (dynamic_cast<C*>(p))
    std::cout << "Type: C\n";
  else
    std::cerr << "Invalid pointer\n";
}

void identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Type: A\n";
	} 
	catch (const std::exception& e1) {
		try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Type: B\n";
		}
		catch (const std::exception& e2) {
			try {
				C c = dynamic_cast<C&>(p);
				std::cout << "Type: C\n";
			}
			catch (const std::exception& e3) {
				std::cerr << "Invalid reference\n";
			}
		}
	}
}

int main (void) {
	Base *random = generate();
	A *a = new A();
	B *b = new B();
	C *c = new C();

	std::cout << "\nType A test:\n";
	identify(a);
	identify(*a);

	std::cout << "\nType B test:\n";
	identify(b);
	identify(*b);

	std::cout << "\nType C test:\n";
	identify(c);
	identify(*c);

	std::cout << "\nRandom type test:\n";
	identify(random);
	identify(*random);

	delete (a);
	delete (b);
	delete (c);
	delete (random);

  	return (0);
}
