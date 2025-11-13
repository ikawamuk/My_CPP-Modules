#ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(const Name& name);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& rhs);
		~FragTrap();
		void	attack(const std::string& target);
		void	highFivesGuys(void);

	protected:
		FragTrap(void);
		static unsigned int	init_hit_points(void);
		static unsigned int	init_energy_points(void);
		static unsigned int	init_attack_damage(void);
		const char*			class_name(void) const;
};

#endif
