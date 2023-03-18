#ifndef SPAN_TPP
# define SPAN_TPP

# include "Span.hpp"

template <typename T>
void Span::addRange(T begin, T end) {
	unsigned int space = this->max - this->vect.size();

	if (std::distance(begin, end) > space)
		throw NotEnoughCapacity();
	while (begin != end) {
		this->vect.push_back(*begin);
		begin++;
 	}
}

#endif
