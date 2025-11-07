#include "HitPoints.hpp"
#include <limits>
#include <stdexcept>
#include <iostream>

HitPoints::HitPoints(unsigned int value)
:value_(value)
{}

HitPoints::HitPoints(const HitPoints& other)
:value_(other.value_)
{}

HitPoints& HitPoints::operator=(const HitPoints& rhs)
{
	if (this != &rhs)
		value_ = rhs.value_;
	return (*this);
}

HitPoints::~HitPoints()
{}

unsigned int	HitPoints::value(void) const
{
	return (value_);
}

HitPoints	HitPoints::increase_value(unsigned int amount) const
{
	unsigned int		value = value_;
	const unsigned int	MAX = std::numeric_limits<unsigned int>::max();

	if (amount < MAX - value_)
		value += amount;
	else
		value = MAX;
	return (HitPoints(value));
}

HitPoints	HitPoints::decrease_value(unsigned int amount) const
{
	unsigned int		value = value_;

	if (amount < value)
		value -= amount;
	else
		value = 0;
	return (HitPoints(value));
}

std::ostream&	operator<<(std::ostream& os, const HitPoints& hit_points)
{
	os << hit_points.value();
	return (os);
}
