#ifndef VEC2D_HPP_
# define VEC2D_HPP_

#include "Fixed.hpp"
#include "Point.hpp"

class Vec2d
{
	public:
		Vec2d(void);
		Vec2d(const Vec2d& other);
		Vec2d(const Point& init, const Point& term);
		Vec2d(const Fixed& x_, const Fixed& y_);
		~Vec2d();
		Vec2d&	operator=(const Vec2d& rhs);
		Vec2d&	operator+=(const Vec2d& rhs);
		Vec2d&	operator-=(const Vec2d& rhs);
		Vec2d&	operator*=(const Fixed& rhs);
		Vec2d&	operator/=(const Fixed& rhs);
		Vec2d	operator+(const Vec2d& rhs) const;
		Vec2d	operator-(const Vec2d& rhs) const;
		Vec2d	operator*(const Fixed& rhs) const;
		Vec2d	operator/(const Fixed& rhs) const;
		Fixed	dot(const Vec2d& rhs) const;
		Fixed	cross_scalar(const Vec2d& rhs) const;

	private:
		Fixed	x_;
		Fixed	y_;
};

#endif
