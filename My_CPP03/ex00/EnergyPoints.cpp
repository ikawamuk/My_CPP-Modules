#include "EnergyPoints.hpp"
#include <limits>
#include <stdexcept>
#include <iostream>

EnergyPoints::EnergyPoints(unsigned int value)
:value_(value)
{}

EnergyPoints::EnergyPoints(const EnergyPoints& other)
:value_(other.value_)
{}

EnergyPoints::~EnergyPoints()
{}

EnergyPoints& EnergyPoints::operator=(const EnergyPoints& rhs)
{
	if (this != &rhs)
		value_ = rhs.value_;
	return (*this);
}

unsigned int	EnergyPoints::value(void) const
{
	return (value_);
}

EnergyPoints	EnergyPoints::decrement_value(void) const
{
	return (decrease_value());
}

EnergyPoints	EnergyPoints::decrease_value(unsigned int amount) const
{
	unsigned int		value = value_;

	if (amount < value)
		value -= amount;
	else
		value = 0;
	return (EnergyPoints(value));
}

std::ostream&	operator<<(std::ostream& os, const EnergyPoints& energy_points)
{
	os << energy_points.value();
	return (os);
}
