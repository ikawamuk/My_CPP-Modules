#ifndef CLAPTRAPFACTORY_HPP_
# define CLAPTRAPFACTORY_HPP_

#include "ClapTrap.hpp"
#include "TrapFactory.hpp"

class ClapTrapFactory: public TrapFactory
{
	public:
		~ClapTrapFactory();
		ClapTrap* make(const std::string& s) const;

	protected:
		ClapTrap*	generate_object(const Name& name, const HitPoints& hp, const EnergyPoints& ep, const Attackdamage& ad) const;
		unsigned int	set_initial_hit_points() const;
		unsigned int	set_initial_energy_points() const;
		unsigned int	set_initial_attack_damage() const;
};

#endif
