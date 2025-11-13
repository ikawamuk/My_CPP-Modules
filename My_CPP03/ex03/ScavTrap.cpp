#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const Name& name)
:ClapTrap(name, HitPoints(init_hit_points()), EnergyPoints(init_energy_points()), AttackDamage(init_attack_damage()))
{
	std::cout << BLUE;
	std::cout << "Scav parameterized constructorcalled! (name)";
	std::cout << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
:ClapTrap(other)
{
	std::cout << BLUE;
	std::cout << "Scav copy constructor called!";
	std::cout << RESET << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << BLACK;
	std::cout << "Scav destructor called!";
	std::cout << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!can_take_action())
		return ;
	ClapTrap::attack(target);
	std::cout << YELLOW;
	std::cout << name() << " scavenged an item!";
	std::cout << RESET << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << MAGENTA;
	std::cout << class_name() << " " << name() << " is in gatekeeper mode now!";
	std::cout << RESET << std::endl;
}

ScavTrap::ScavTrap(void)
{
	std::cout << BLUE;
	std::cout << "Scav default constructor called!" << std::endl;
	std::cout << RESET;
}

unsigned int	ScavTrap::init_hit_points(void)
{
	return (100);
}

unsigned int	ScavTrap::init_energy_points(void)
{
	return (50);
}

unsigned int	ScavTrap::init_attack_damage(void)
{
	return (20);
}

const char*	ScavTrap::class_name(void) const
{
	return ("ScavTrap");
}
