#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>

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

static void	validate_out_of_range_i(const int int_value, const double SCALE);
Fixed::Fixed(const int int_value)
{
	const int SCALE = 1 << FRACTIONAL_BITS;

	std::cout << "Int constructor called" << std::endl;
	validate_out_of_range_i(int_value, SCALE);
	value_ = int_value * SCALE;
}

static void	validate_out_of_range_i(const int int_value, const double SCALE)
{
	if (int_value > (std::numeric_limits<int>::max() / SCALE)
	|| int_value < (std::numeric_limits<int>::min() / SCALE))
		throw std::overflow_error("Fixed-point overflow");
	return ;
}

static void	validate_out_of_range_f(const double d_float_value, const double	SCALE);
static bool	is_fnun(const float f);
static bool	is_finf(const float f);
Fixed::Fixed(const float float_value)
{
	const double	d_float_value = static_cast<double>(float_value);
	const double	SCALE = std::ldexp(1.0, FRACTIONAL_BITS);

	std::cout << "Float constructor called" << std::endl;
	validate_out_of_range_f(d_float_value, SCALE);
	const double	scaled_value = d_float_value * SCALE;
	const double	bias = (scaled_value >= 0.0) ? 0.5 : -0.5;
	value_ = static_cast<int>(scaled_value + bias);
	return ;
}

static void	validate_out_of_range_f(const double d_float_value, const double SCALE)
{
	if (is_fnun(d_float_value) || is_finf(d_float_value))
		throw std::runtime_error("Invalid float: NaN or Inf");
	if (d_float_value > static_cast<double>(std::numeric_limits<int>::max() / SCALE - 0.5 / SCALE)
	|| d_float_value < static_cast<double>(std::numeric_limits<int>::min() / SCALE + 0.5 / SCALE))
		throw std::overflow_error("Fixed-point overflow");
	return ;
}

static bool	is_fnun(const float f)
{
	return (f != f);
}

static bool	is_finf(const float f)
{
	const float	inf = std::numeric_limits<float>::infinity();

	return (f == inf || f == -inf);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

