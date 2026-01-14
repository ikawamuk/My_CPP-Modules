#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
:value_(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		value_ = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value_);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value_ = raw;
	return ;
}
