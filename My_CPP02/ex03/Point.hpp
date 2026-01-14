#ifndef POINT_HPP_
# define POINT_HPP_

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const int x, const int y);
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& other);
		~Point();
		Point&	operator=(const Point& rhs);
		const Fixed&	get_x(void) const;
		const Fixed&	get_y(void) const;

	private:
		Fixed const x;
		Fixed const y;
};

#endif
