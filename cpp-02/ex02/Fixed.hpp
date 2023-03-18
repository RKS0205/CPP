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
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const bits);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed &operator =(Fixed const &fixed);

		bool operator< (Fixed const &fixed) const;
		bool operator> (Fixed const &fixed) const;
		bool operator>=(Fixed const &fixed) const;
		bool operator<=(Fixed const &fixed) const;
		bool operator==(Fixed const &fixed) const;
		bool operator!=(Fixed const &fixed) const;

		Fixed operator+(Fixed const &fixed) const;
		Fixed operator-(Fixed const &fixed) const;
		Fixed operator*(Fixed const &fixed) const;
		Fixed operator/(Fixed const &fixed) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(Fixed const &f1, Fixed const &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(Fixed const &f1, Fixed const &f2);

};

std::ostream &operator <<(std::ostream &out, Fixed const &f);

#endif
