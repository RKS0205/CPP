#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;

	if (argc != 2)
		return (0);
	std::string command = argv[1];
	harl.complain(command);
}
