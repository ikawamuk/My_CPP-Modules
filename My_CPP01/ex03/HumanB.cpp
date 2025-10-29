#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name)
:name_b_(name)
,weapon_b_(NULL)
{}

void	HumanB::attack(void) const
{
	if (weapon_b_)
		std::cout << name_b_ << " attacks with their " << weapon_b_->getType() << std::endl;
	else
		std::cout << name_b_ << " has no weapon..." << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon* newWeapon)
{
	weapon_b_ = newWeapon;
	return ;
}
