#include "Vec2d.hpp"

Vec2d&	Vec2d::operator=(const Vec2d& rhs)
{
	if (this != &rhs)
	{
		x_ = rhs.x_;
		y_ = rhs.y_;
	}
	return *this;
}

Vec2d& Vec2d::operator+=(const Vec2d& rhs)
{
	x_ = x_ + rhs.x_;
	y_ = y_ + rhs.y_;
	return (*this);
}

Vec2d& Vec2d::operator-=(const Vec2d& rhs)
{
	x_ = x_ - rhs.x_;
	y_ = y_ - rhs.y_;
	return (*this);
}

Vec2d& Vec2d::operator*=(const Fixed& rhs)
{
	this->x_ *= rhs;
	this->y_ *= rhs;
	return (*this);
}

Vec2d& Vec2d::operator/=(const Fixed& rhs)
{
	this->x_ /= rhs;
	this->y_ /= rhs;
	return (*this);
}

Vec2d	Vec2d::operator+(const Vec2d& rhs) const
{
	Vec2d	sum(*this);

	sum += rhs;
	return (sum);
}

Vec2d	Vec2d::operator-(const Vec2d& rhs) const
{
	Vec2d	dif(*this);

	dif -= rhs;
	return (dif);
}

Vec2d	Vec2d::operator*(const Fixed& rhs) const
{
	Vec2d	pro(*this);

	pro *= rhs;
	return (pro);
}

Vec2d	Vec2d::operator/(const Fixed& rhs) const
{
	Vec2d	quo(*this);

	quo /= rhs;
	return (quo);
}
