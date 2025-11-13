#ifndef SCAVTRAP_HPP_
# define SCAVTRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(const Name& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& rhs);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate(void);

	protected:
		ScavTrap(void);
		static unsigned int	init_hit_points(void);
		static unsigned int	init_energy_points(void);
		static unsigned int	init_attack_damage(void);
		const char*			class_name(void) const;
};

#endif
