#ifndef HUMANB_HPP_
# define HUMANB_HPP_

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void	attack(void) const;
		void	setWeapon(Weapon* newWeapon);

	private:
		HumanB(void);

		std::string	name_b_;
		Weapon		*weapon_b_;
};


#endif