#ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

#include "ClapTrap.hpp"

static const char* const CYAN = "\x1b[36m";

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(const std::string& name = "John Fravolta", int hit_points = 100, int energy_points = 100, int attack_damage = 30);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& rhs);
		virtual ~FragTrap();
		void	attack(const std::string& target);
		void	 highFivesGuys(void);
};

#endif
