#include "EnergyPoints.hpp"

EnergyPoints::EnergyPoints(void)
:NumericParameter()
{}

EnergyPoints::EnergyPoints(int value)
:NumericParameter(value)
{}

EnergyPoints::EnergyPoints(unsigned int value)
:NumericParameter(value)
{}

EnergyPoints::EnergyPoints(long value)
:NumericParameter(value)
{}

EnergyPoints::EnergyPoints(unsigned long value)
:NumericParameter(value)
{}

EnergyPoints::EnergyPoints(const EnergyPoints& other)
:NumericParameter(other)
{}

EnergyPoints::~EnergyPoints()
{}

EnergyPoints&	EnergyPoints::operator=(const EnergyPoints& rhs)
{
	if (this != &rhs)
		NumericParameter::operator=(rhs);
	return (*this);
}
