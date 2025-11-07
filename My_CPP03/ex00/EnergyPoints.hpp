#ifndef ENERGYPOINTS_HPP_
# define ENERGYPOINTS_HPP_

#include <iostream>

class EnergyPoints
{
	public:
		explicit EnergyPoints(unsigned int value = 0);
		EnergyPoints(const EnergyPoints& other);
		~EnergyPoints();
		EnergyPoints&	operator=(const EnergyPoints& rhs);
		unsigned int	value(void) const;
		EnergyPoints	decrement_value(void) const;

	private:
		unsigned int	value_;
		EnergyPoints	decrease_value(unsigned int amount = 1) const;
};

std::ostream&	operator<<(std::ostream& os, const EnergyPoints& energy_points);

#endif
