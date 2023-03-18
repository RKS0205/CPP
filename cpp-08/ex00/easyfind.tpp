#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	typename T::iterator iter = std::find(container.begin(), container.end(), n);

	if (iter == container.end()) {
		throw std::runtime_error(std::string("Value not found"));
	}
	return (iter);
}

#endif
