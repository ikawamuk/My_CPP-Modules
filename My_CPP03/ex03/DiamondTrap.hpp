#ifndef DIAMONDTRAP_HPP_
# define DIAMONDTRAP_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(const Name& name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap& rhs);
		~DiamondTrap();
		void	attack(const std::string& target);
		void	whoAmI(void);

	protected:
		DiamondTrap(void);
		const Name&			name(void) const;
		static unsigned int	init_hit_points(void);
		static unsigned int	init_energy_points(void);
		static unsigned int	init_attack_damage(void);
		const char*			class_name(void) const;

	private:
		Name	name_;
};

#endif
