#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon)
:name_a_(name)
,weapon_a_(weapon)
{}

void	HumanA::attack(void) const
{
	std::cout << name_a_ << " attacks with their " << weapon_a_.getType() << std::endl;
	return ;
}

void	HumanA::setWeapon(Weapon& newWeapon)
{
	weapon_a_ = newWeapon;
	return ;
}
