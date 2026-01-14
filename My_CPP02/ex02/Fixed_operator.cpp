#include "Fixed.hpp"
#include <limits>

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		value_ = other.getRawBits();
	}
	return (*this);
}

bool Fixed::operator> (const Fixed& rhs) const
{
	return (value_ > rhs.value_);
}

bool Fixed::operator< (const Fixed& rhs) const
{
	return (value_ < rhs.value_);
}

bool Fixed::operator>= (const Fixed& rhs) const
{
	return (value_ >= rhs.value_);
}

bool Fixed::operator<= (const Fixed& rhs) const
{
	return (value_ <= rhs.value_);
}

bool Fixed::operator== (const Fixed& rhs) const
{
	return (value_ == rhs.value_);
}

bool Fixed::operator!= (const Fixed& rhs) const
{
	return (value_ != rhs.value_);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed	result;
	const long	sum = static_cast<long>(this->value_) + static_cast<long>(rhs.value_);

	if (sum > std::numeric_limits<int>::max() || sum < std::numeric_limits<int>::min())
		throw std::overflow_error("Fixed-point overflow");
	result.setRawBits(static_cast<int>(sum));
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed	result;
	const long	diff = static_cast<long>(this->value_) - static_cast<long>(rhs.value_);

	if (diff > std::numeric_limits<int>::max() || diff < std::numeric_limits<int>::min())
		throw std::overflow_error("Fixed-point overflow");
	result.setRawBits(static_cast<int>(diff));
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed	result;
	long	prod = static_cast<long>(this->value_) * static_cast<long>(rhs.value_);
	const long	eps_half = 1L << (FRACTIONAL_BITS - 1);
	const long	bias = (prod >= 0.0) ? eps_half : -eps_half;
	const long	biased_prod = prod + bias;
	const long	scaled_prod = biased_prod / (1L << FRACTIONAL_BITS);
	if (scaled_prod > std::numeric_limits<int>::max() || scaled_prod < std::numeric_limits<int>::min())
		throw std::overflow_error("Fixed-point overflow");
	result.setRawBits(static_cast<int>(scaled_prod));
	return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	if (rhs.value_ == 0)
		throw std::domain_error("division by zero");
	Fixed	result;
	long	num = static_cast<long>(this->value_) * (1L << FRACTIONAL_BITS);
	long	div = static_cast<long>(rhs.value_);
	long	quo = num / div;
	if (quo < std::numeric_limits<int>::min() || quo > std::numeric_limits<int>::max())
		throw std::overflow_error("overflow");
	result.setRawBits(static_cast<int>(quo));
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	value_++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	value_++;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	value_--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	value_--;
	return (tmp);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
