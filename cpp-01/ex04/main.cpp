#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
	std::ifstream infile;
	std::ofstream outfile;
	std::stringstream ss;
	std::string	outfile_name;
	std::string infile_string;
	std::string outfile_string;
	size_t pos;
	size_t start;

	if (argc != 4) {
		std::cout << "Incorrect number of parameters" << std::endl;
		return (0);
	}
	infile.open(argv[1]);
	if (infile.fail()) {
		std::cout << "Error opening file" << std::endl;
		return (0);
	}
	outfile_name = std::string(argv[1]) + ".replace";
	outfile.open(outfile_name.c_str());
		if (outfile.fail()) {
		std::cout << "Error creating file" << std::endl;
		return (0);
	}
	ss << infile.rdbuf();
	infile_string = ss.str();
	pos = infile_string.find(argv[2]);
	start = 0;
	while (pos != std::string::npos) {
		outfile_string.append(infile_string.substr(start, pos - start));
		start = pos + std::string(argv[2]).length();
		outfile_string.append(argv[3]);
		pos = infile_string.find(argv[2], pos + 1);
	}
	outfile_string.append(infile_string.substr(start, infile_string.length() - start));
	outfile << outfile_string;
	infile.close();
	outfile.close();
}
