#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(Name name, HitPoints hit_points, EnergyPoints energy_points, Attackdamage attack_damage)
:Trap(name, hit_points, energy_points, attack_damage)
{
	std::cout << "ClapTrap constracter with parameter is called!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
:Trap(other)
{
	std::cout << "ClapTrap copy constracter is called!!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
		Trap::operator=(rhs);
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << class_name() << " denstracter is called!!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	Trap::attack(target);
	return ;
}

ClapTrap::ClapTrap(void)
:Trap()
{
	std::cout << "ClapTrap default constracter is called!!" << std::endl;
}

const std::string ClapTrap::class_name(void) const
{
	return ("ClapTrap");
}
