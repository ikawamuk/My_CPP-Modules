#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name,int hit_points, int energy_points, int attack_damage)
:ClapTrap(name, hit_points, energy_points, attack_damage)
{
	std::cout << GREEN << "the Frag default constructor called!!" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& other)
:ClapTrap(other)
{
	std::cout << GREEN << "the Frag copy constructor called!!" << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << RESET << "the Frag assignment operator called!!" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << BLUE << "the Frag destructor called!!" << std::endl;
	return ;
}

void	FragTrap::attack(const std::string& target)
{
	if (!can_take_action())
		return ;
	set_energy_points(energy_points() - 1);
	std::cout << YELLOW;
	std::cout << "FragTrap "<< name() \
			<< " attacks "<< target \
			<< ", causing "<< attack_damage() << " points of damage!" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << CYAN;
	std::cout << "FragTrap " << name() << " looks at you as if it wants to high-five!" << std::endl;
}
