#ifndef ENERGYPOINTS_HPP_
# define ENERGYPOINTS_HPP_

#include <ostream>
#include "NumericParameter.hpp"

class EnergyPoints: public NumericParameter
{
	public:
		explicit EnergyPoints(void);
		explicit EnergyPoints(int value);
		explicit EnergyPoints(unsigned int value);
		explicit EnergyPoints(long value);
		explicit EnergyPoints(unsigned long value);
		EnergyPoints(const EnergyPoints& other);
		~EnergyPoints();
		EnergyPoints&	operator=(const EnergyPoints& rhs);
		using NumericParameter::value;

	private:
		using NumericParameter::operator+=;
		using NumericParameter::operator-=;
};

#endif
