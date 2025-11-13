#include "NumericParameter.hpp"
#include <stdexcept>
#include <limits>

NumericParameter::NumericParameter(void)
:value_(0)
{}

NumericParameter::NumericParameter(int value)
:value_(validate_signed(value))
{}

NumericParameter::NumericParameter(unsigned int value)
:value_(validate_unsigned(value))
{}

NumericParameter::NumericParameter(long value)
:value_(validate_signed(value))
{}

NumericParameter::NumericParameter(unsigned long value)
:value_(validate_unsigned(value))
{}

NumericParameter::NumericParameter(const NumericParameter& other)
:value_(other.value_)
{}

NumericParameter::~NumericParameter()
{}

NumericParameter& NumericParameter::operator=(const NumericParameter& rhs)
{
	if (this != &rhs)
		value_ = rhs.value_;
	return (*this);
}

unsigned int	NumericParameter::value(void) const
{
	return (value_);
}

namespace
{
	unsigned int add_saturate(unsigned int value, unsigned long amount)
	{
		const unsigned long UMAX = std::numeric_limits<unsigned int>::max();
		if (amount > UMAX - value)
			return static_cast<unsigned int>(UMAX);
		return (static_cast<unsigned int>(value + amount));
	}

	unsigned int sub_saturate(unsigned int value, unsigned long amount)
	{
		if (amount >= value)
			return 0;
		return (static_cast<unsigned int>(value - amount));
	}
}

NumericParameter&	NumericParameter::operator+=(unsigned long amount)
{
	value_ = add_saturate(value_, amount);
	return (*this);
}

NumericParameter&	NumericParameter::operator-=(unsigned long amount)
{
	value_ = sub_saturate(value_, amount);
	return (*this);
}

NumericParameter&	NumericParameter::operator--(void)
{
	return (*this -= 1);
}

NumericParameter	NumericParameter::operator--(int)
{
	NumericParameter	rev(*this);

	--(*this);
	return (rev);
}

unsigned int	NumericParameter::validate_signed(long value)
{
	if (value < 0)
		throw std::invalid_argument("numeric paraeter must be >= 0");
	return (validate_unsigned(static_cast<unsigned long>(value)));
}

unsigned int	NumericParameter::validate_unsigned(unsigned long value)
{
	 const unsigned long UMAX = std::numeric_limits<unsigned int>::max();
	 if (value > UMAX) throw std::out_of_range("numeric parameter overflow");
	return (static_cast<unsigned int>(value));
}

std::ostream&	operator<<(std::ostream& os, const NumericParameter& numeric_parameter)
{
	os << numeric_parameter.value();
	return (os);
}

long	operator-(const NumericParameter& lhs, const NumericParameter& rhs)
{
	return (static_cast<long>(lhs.value()) - static_cast<long>(rhs.value()));
}
