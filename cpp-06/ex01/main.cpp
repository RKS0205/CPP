#include "Data.hpp"
#include <stdint.h>
#include <iostream>

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

int main (void) {
	Data *start = new Data("test");

	uintptr_t after_serial = serialize(start);

	Data *end = deserialize(after_serial);

	std::cout << "Address before serialization: " << start << "\n";
	std::cout << "Data string: " << start->getInput() << "\n\n";

	std::cout << "Address after deserialization: " << end << "\n"; 
	std::cout << "Data string: " << end->getInput() << "\n";

	delete start;
	return (0);
}
