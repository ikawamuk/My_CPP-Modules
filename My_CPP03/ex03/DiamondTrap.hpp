#ifndef DIAMONDTRAP_HPP_
# define DIAMONDTRAP_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static const char* const WHITE = "\x1b[30m";

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(const std::string& name = "John Diavolta");
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap& rhs);
		~DiamondTrap();
		void	whoAmI(void);
		using ScavTrap::attack;

	private:
		std::string	name_;
		using ClapTrap::name;
		using FragTrap::hit_points;
		using ScavTrap::energy_points;
		using FragTrap::attack_damage;
};

#endif
