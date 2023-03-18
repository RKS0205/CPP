#include "Convert.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
		std::string input = argv[1];
		Convert conv(input);
		conv.printResult();
	}
	else {
		std::cerr << "Incorrect number of parameters\n";
	}
}
