#ifndef HITPOINTS_HPP_
# define HITPOINTS_HPP_

#include <ostream>
#include "NumericParameter.hpp"

class HitPoints: public NumericParameter
{
	public:
		explicit HitPoints(void);
		explicit HitPoints(int value);
		explicit HitPoints(unsigned int value);
		explicit HitPoints(long value);
		explicit HitPoints(unsigned long value);
		HitPoints(const HitPoints& other);
		~HitPoints();
		HitPoints&	operator=(const HitPoints& rhs);
		using NumericParameter::value;

	private:
		using NumericParameter::operator--;
};

#endif
