#ifndef HITPOINTS_HPP_
# define HITPOINTS_HPP_

#include <iostream>

class HitPoints
{
	public:
		explicit HitPoints(unsigned int value = 0);
		HitPoints(const HitPoints& other);
		HitPoints& operator=(const HitPoints& rhs);
		~HitPoints();
		unsigned int	value(void) const;
		HitPoints	increase_value(unsigned int amount) const;
		HitPoints	decrease_value(unsigned int amount) const;

	private:
		unsigned int	value_;
};

std::ostream&	operator<<(std::ostream& os, const HitPoints& hit_points);

#endif
