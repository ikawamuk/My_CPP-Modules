#ifndef ATTACKDAMAGE_HPP_
# define ATTACKDAMAGE_HPP_

#include <iostream>

class Attackdamage
{
	public:
		explicit Attackdamage(unsigned int value = 0);
		Attackdamage(const Attackdamage& other);
		~Attackdamage();
		Attackdamage&	operator=(const Attackdamage& rhs);
		unsigned int	value(void) const;

	private:
		unsigned int	value_;
};

std::ostream&	operator<<(std::ostream& os, const Attackdamage& attack_damage);

#endif
