#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

#include "Trap.hpp"


class ClapTrap: public Trap
{
	public:
		ClapTrap(Name name);
		ClapTrap(Name name, HitPoints hit_points, EnergyPoints energy_points, Attackdamage attack_damage);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();
		ClapTrap&	operator=(const ClapTrap& rhs);
		void		attack(const std::string& target);

	protected:
		ClapTrap(void);
		const std::string	class_name(void) const;
};

#endif
