#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <deque>
# include <list>
# include <iostream>
# include <algorithm>
# include <string>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int n);

# include "easyfind.tpp"

#endif
