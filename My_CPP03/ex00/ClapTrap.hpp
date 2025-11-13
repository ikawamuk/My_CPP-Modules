#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

#include <string>
#include "Name.hpp"
#include "HitPoints.hpp"
#include "EnergyPoints.hpp"
#include "AttackDamage.hpp"

class ClapTrap
{
	public:
		ClapTrap(const Name& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& rhs);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		ClapTrap(void);
		ClapTrap(const Name& name, const HitPoints& hit_points, const EnergyPoints& energy_points, const AttackDamage& attack_damage);
		const Name&			name(void) const;
		const HitPoints&	hit_points(void) const;
		const EnergyPoints&	energy_points(void) const;
		const AttackDamage&	attack_damage(void) const;
		static unsigned int	init_hit_points(void);
		static unsigned int	init_energy_points(void);
		static unsigned int	init_attack_damage(void);
		const char*			class_name(void) const;
		bool				can_take_action(void) const;

	private:
		Name			name_;
		HitPoints		hit_points_;
		EnergyPoints	energy_points_;
		AttackDamage	attack_damage_;
};

const char RESET[]		= "\x1b[0m";
const char BLACK[]		= "\x1b[30m";
const char RED[]		= "\x1b[31m";
const char GREEN[]		= "\x1b[32m";
const char YELLOW[]		= "\x1b[33m";
const char BLUE[]		= "\x1b[34m";
const char MAGENTA[]	= "\x1b[35m";
const char CYAN[]		= "\x1b[36m";

#endif
