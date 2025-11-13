#include "HitPoints.hpp"

HitPoints::HitPoints(void)
:NumericParameter()
{}

HitPoints::HitPoints(int value)
:NumericParameter(value)
{}

HitPoints::HitPoints(unsigned int value)
:NumericParameter(value)
{}

HitPoints::HitPoints(long value)
:NumericParameter(value)
{}

HitPoints::HitPoints(unsigned long value)
:NumericParameter(value)
{}

HitPoints::~HitPoints()
{}

HitPoints::HitPoints(const HitPoints& other)
:NumericParameter(other)
{}

HitPoints&	HitPoints::operator=(const HitPoints& rhs)
{
	if (this != &rhs)
		NumericParameter::operator=(rhs);
	return (*this);
}

HitPoints::operator	bool(void) const
{
	return (this->value());
}

bool	HitPoints::operator!(void) const
{
	return (!this->value());
}
