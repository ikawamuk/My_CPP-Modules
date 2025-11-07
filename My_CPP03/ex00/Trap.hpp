#ifndef TRAP_HPP_
# define TRAP_HPP_

#include "Name.hpp"
#include "HitPoints.hpp"
#include "EnergyPoints.hpp"
#include "AttackDamage.hpp"

class Trap
{
	public:
		Trap(Name name, HitPoints hit_points, EnergyPoints energy_points, Attackdamage attack_damage);
		Trap(const Trap& other);
		Trap&	operator=(const Trap& rhs);
		virtual ~Trap();
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	protected:
		Trap(void);
		const Name&					name(void) const;
		const HitPoints&			hit_points(void) const;
		const EnergyPoints&			energy_points(void) const;
		const Attackdamage&			attack_damage(void) const;
		virtual const std::string	class_name(void) const;

	private:
		Name			name_;
		HitPoints		hit_points_;
		EnergyPoints	energy_points_;
		Attackdamage	attack_damage_;
};

#endif
