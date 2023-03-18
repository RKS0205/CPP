#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* address, int len, void(*f)(const T&)) {
	for (int i = 0; i < len; i++) {
		f(address[i]);
	}
}

template <typename T>
void print(const T& a) {
	std::cout << a << "\n";
}

#endif
