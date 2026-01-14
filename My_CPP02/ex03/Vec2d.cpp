#include "Vec2d.hpp"

Fixed	Vec2d::dot(const Vec2d& rhs) const
{
	return ((this->x_ * rhs.y_) + (this->y_ * rhs.x_));
}

Fixed	Vec2d::cross_scalar(const Vec2d& rhs) const
{
	return ((this->x_ * rhs.y_) - (this->y_ * rhs.x_));
}
