#ifndef SCAVTRAP_HPP_
# define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

static const char* const MAGENTA = "\x1b[35m";

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(const std::string& name = "John Scavolta", int hit_points = 100, int energy_points = 50, int attack_damage = 20);
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& rhs);
		virtual ~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif
