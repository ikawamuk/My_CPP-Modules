#include "Point.hpp"

Point::Point(void)
:x(0), y(0)
{}

Point::Point(const float x, const float y)
:x(x), y(y)
{}

Point::Point(const int x, const int y)
:x(x), y(y)
{}

Point::Point(const Fixed& x, const Fixed& y)
:x(x), y(y)
{}

Point::Point(const Point& other)
:x(other.x), y(other.y)
{}

Point::~Point()
{}

Point&	Point::operator=(const Point& rhs)
{
	(void)rhs;
	throw std::logic_error("assignment to a class with const-only members");
}

const Fixed&	Point::get_x(void) const
{
	return (x);
}

const Fixed&	Point::get_y(void) const
{
	return (y);
}
