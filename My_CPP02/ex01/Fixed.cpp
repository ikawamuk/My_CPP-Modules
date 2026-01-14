#include "Fixed.hpp"
#include <iostream>
#include <limits>
#include <cmath>

int	Fixed::getRawBits(void) const
{
	return (value_);
}

void	Fixed::setRawBits(int const raw)
{
	value_ = raw;
	return ;
}

int	Fixed::toInt(void) const
{
	return (value_ >> FRACTIONAL_BITS);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(std::ldexp(static_cast<double>(value_), -FRACTIONAL_BITS)));
}
