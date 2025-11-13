#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const Name& name)
:ClapTrap(name, HitPoints(init_hit_points()), EnergyPoints(init_energy_points()), AttackDamage(init_attack_damage()))
{
	std::cout << BLUE;
	std::cout << "Frag parameterized consTructorcalled! (name)";
	std::cout << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
:ClapTrap(other)
{
	std::cout << BLUE;
	std::cout << "Frag copy consTructor called!";
	std::cout << RESET << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << BLACK;
	std::cout << "Frag desTructor called!";
	std::cout << RESET << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (!can_take_action())
		return ;
	ClapTrap::attack(target);
	std::cout << YELLOW;
	std::cout << "Boom! Big explosion!";
	std::cout << RESET << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << CYAN;
	std::cout << class_name() << " " << name() << " is looking at you as if he wanna give you a high five!";
	std::cout << RESET << std::endl;
}

FragTrap::FragTrap(void)
{
	std::cout << BLUE;
	std::cout << "Frag default constructor called!" << std::endl;
	std::cout << RESET;
}

unsigned int	FragTrap::init_hit_points(void)
{
	return (100);
}

unsigned int	FragTrap::init_energy_points(void)
{
	return (100);
}

unsigned int	FragTrap::init_attack_damage(void)
{
	return (30);
}

const char*	FragTrap::class_name(void) const
{
	return ("FragTrap");
}
