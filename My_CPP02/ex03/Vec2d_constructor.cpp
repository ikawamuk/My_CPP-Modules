#include "Vec2d.hpp"

Vec2d::Vec2d(void)
:x_(0), y_(0)
{}

Vec2d::Vec2d(const Vec2d& other)
:x_(other.x_), y_(other.y_)
{}

Vec2d::Vec2d(const Point& init, const Point& term)
:x_(term.get_x() - init.get_x()), y_(term.get_y() - init.get_y())
{}

Vec2d::Vec2d(const Fixed& x, const Fixed& y)
:x_(x), y_(y)
{}

Vec2d::~Vec2d()
{}
