#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name,int hit_points, int energy_points, int attack_damage)
:ClapTrap(name, hit_points, energy_points, attack_damage)
{
	std::cout << GREEN << "the Scav default constructor called!!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& other)
:ClapTrap(other)
{
	std::cout << GREEN << "the Scav copy constructor called!!" << std::endl;
	return ;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << RESET << "the Scav assignment operator called!!" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << BLUE << "the Scav destructor called!!" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!can_take_action())
		return ;
	set_energy_points(energy_points() - 1);
	std::cout << YELLOW;
	std::cout << "ScavTrap "<< name() \
			<< " attacks "<< target \
			<< ", causing "<< attack_damage() << " points of damage!" << std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << MAGENTA;
	std::cout << "ScavTrap " << name() << " is now in Gate keeper mode!!" << std::endl;
}
