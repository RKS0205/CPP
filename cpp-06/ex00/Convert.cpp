#include "Convert.hpp"

Convert::Convert(void) {
}

Convert::~Convert(void) {
}

Convert::Convert(const std::string input) : input(input) {
	char check;

	check = this->checkInputType();
	if (check == 'c') {
		this->useDataFromChar();
	}
	if (check == 'i') {
		this->useDataFromInt();
	}
	if (check == 'd') {
		this->useDataFromDouble();
	}
	if (check == 'f') {
		this->useDataFromFloat();
	}
	if (check == 0) {
		this->useDataFromNothing();
		return ;
	}
	this->insertIntoString();
}

Convert::Convert(const Convert &c) {
	*this = c;
}

Convert& Convert::operator=(const Convert &c) {
	this->input = c.input;
	this->c = c.c;
	this->d = c.d;
	this->f = c.f;
	this->i = c.i;
	return (*this);
}

char Convert::checkInputType(void) {
	char *check;

	if (this->input.length() == 1 && std::isalpha(this->input[0])) {
		this->c = this->input[0];
		return ('c');
	}
	strtol(this->input.c_str(), &check, 10);
	if (*check == '\0') { 
		this->i = static_cast<int>(strtol(this->input.c_str(), NULL, 10));
		return ('i');
	}
	strtod(this->input.c_str(), &check);
	if (*check == '\0') {
		this->d = strtod(this->input.c_str(), &check);
		return ('d');
	}
	strtof(this->input.c_str(), &check);
	if (*check == 'f' && *(check + 1) == '\0') {
		this->f = strtof(this->input.c_str(), &check);
		return ('f');
	}
	return (0);
}

void Convert::useDataFromChar(void) {
	this->i = static_cast<int>(this->c);
	this->d = static_cast<double>(this->c);
	this->f = static_cast<float>(this->c);
}

void Convert::useDataFromInt(void) {
	this->c = static_cast<char>(this->i);
	this->d = static_cast<double>(this->i);
	this->f = static_cast<float>(this->i);
}

void Convert::useDataFromFloat(void) {
	this->c = static_cast<char>(this->f);
	this->d = static_cast<double>(this->f);
	this->i = static_cast<int>(this->f);
}

void Convert::useDataFromDouble(void) {
	this->c = static_cast<char>(this->d);
	this->i = static_cast<int>(this->d);
	this->f = static_cast<float>(this->d);
}

void Convert::useDataFromNothing(void) {
	char *check;

	this->d = strtod(this->input.c_str(), &check);
	this->f = strtof(this->input.c_str(), &check);
	this->c = 0;
	this->i = 0;
	if (*check != '\0') {
		this->d_out = "impossible";
		this->f_out = "impossible";
		this->c_out = "impossible";
		this->i_out = "impossible";
	}
}

void Convert::insertIntoString(void) {
	std::stringstream ss;

	if (static_cast<double>(this->i) != this->d && this->d_out != "impossible") {
		this->i_out = "impossible";
		this->c_out = "impossible";
		ss << this->d;
		ss >> this->d_out;
		ss.clear();
		ss << this->f << "f";
		ss >> this->f_out;
	}
	else if (this->d_out != "impossible") {
		if (!std::isprint(this->c))
			this->c_out = "Non displayable";
		else {
			ss << "'" << this->c << "'";
			ss >> this->c_out;
			ss.clear();
		}
		ss << this->i;
		ss >> this->i_out;
		ss.clear();
		ss << this->d;
		ss << ".0";
		ss >> this->d_out;
		ss.clear();
		ss << this->f;
		ss << ".0f";
		ss >> this->f_out;
	}
}

void Convert::printResult(void) {
	std::cout << "char: " << this->c_out << "\n";
    std::cout << "int: " << this->i_out << "\n";
    std::cout << "float: " << this->f_out << "\n";
    std::cout << "double: " << this->d_out << "\n";
}
