#include "Fixed.hpp"

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		value_ = other.getRawBits();
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
