#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int rawBits;
		static const int fractional_bits; 
	
	public:
		Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed(const int num);
		Fixed(const float num);
		Fixed &operator =(Fixed const &fixed);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const bits);
		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream &operator <<(std::ostream &out, Fixed const &f);

#endif
