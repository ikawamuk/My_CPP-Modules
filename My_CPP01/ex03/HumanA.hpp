#ifndef HUMANA_HPP_
# define HUMANA_HPP_

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		void	attack(void) const;
		void	setWeapon(Weapon& newWeapon);

	private:
		HumanA(void);

		std::string	name_a_;
		Weapon		&weapon_a_;
};

#endif