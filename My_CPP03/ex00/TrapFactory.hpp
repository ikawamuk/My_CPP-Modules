#ifndef TRAPFACTORY_HPP_
# define TRAPFACTORY_HPP_

#include "Trap.hpp"

class TrapFactory
{
	public:
		virtual ~TrapFactory() = 0;
		virtual Trap*			make(const std::string& name) const;
		virtual Trap*			generate_object(const Name& name, const HitPoints& hp, const EnergyPoints& ep, const Attackdamage& ad) const = 0;
		virtual unsigned int	set_initial_hit_points() const = 0;
		virtual unsigned int	set_initial_energy_points() const = 0;
		virtual unsigned int	set_initial_attack_damage() const = 0;
};

#endif
