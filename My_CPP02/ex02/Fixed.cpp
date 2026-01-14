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

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	return (f1 <= f2 ? f1 : f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	return (f1 >= f2 ? f1 : f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return (f1 <= f2 ? f1 : f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return (f1 >= f2 ? f1 : f2);
}
