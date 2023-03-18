#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &p);
		~Point(void);

		Point &operator=(Point const &p);
		Fixed const getX(void) const;
		Fixed const getY(void) const;
		void setX(Fixed const x);
		void setY(Fixed const y);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
