#include <iostream>
#include "Point.hpp"
#include <sstream>

int main(int argc, char **argv) {
	Point a;
	Point b;
	Point c;
	Point point;
	std::stringstream ss;
  	std::string s;
 	float x;
 	float y;

	if (argc != 9)
	{
		std::cout << "Incorrect parameters" << std::endl;
		return (1);
	}

	s = argv[1];
	ss << s;
	ss >> x;
	ss.clear();
	s = argv[2];
	ss << s;
	ss >> y;
	ss.clear();
	a.setX(Fixed(x));
	a.setY(Fixed(y));

	s = argv[3];
	ss << s;
	ss >> x;
	ss.clear();
	s = argv[4];
	ss << s;
	ss >> y;
	ss.clear();
	b.setX(Fixed(x));
	b.setY(Fixed(y));

	s = argv[5];
	ss << s;
	ss >> x;
	ss.clear();
	s = argv[6];
	ss << s;
	ss >> y;
	ss.clear();
	c.setX(Fixed(x));
	c.setY(Fixed(y));

	s = argv[7];
	ss << s;
	ss >> x;
	ss.clear();
	s = argv[8];
	ss << s;
	ss >> y;
	ss.clear();
	point.setX(Fixed(x));
	point.setY(Fixed(y));

	if (bsp(a, b, c, point))
		std::cout << "Point is in triangle" << std::endl;
	else
		std::cout << "Point is not in triangle" << std::endl;
	return (0);
}
