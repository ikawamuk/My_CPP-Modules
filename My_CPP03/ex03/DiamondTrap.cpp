#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const Name& name)
:ClapTrap(Name(name.value() + "_clup_name"), HitPoints(init_hit_points()), EnergyPoints(init_energy_points()), AttackDamage(init_attack_damage())), name_(name)
{
	std::cout << BLUE;
	std::cout << "Diamond parameterized consTructorcalled! (name)";
	std::cout << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
:ClapTrap(other), ScavTrap(other), FragTrap(other), name_(other.name_)
{
	std::cout << BLUE;
	std::cout << "Diamnond copy consTructor called!";
	std::cout << RESET << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		name_ = rhs.name_;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BLACK;
	std::cout << "Diamond desTructor called!";
	std::cout << RESET << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << name() << ", and  ";
	std::cout << "my ClapTrap name is " << ClapTrap::name() << "." << std::endl;
}

DiamondTrap::DiamondTrap(void)
{
	std::cout << BLUE;
	std::cout << "Diamond default constructor called!" << std::endl;
	std::cout << RESET;
}

const Name&	DiamondTrap::name(void) const
{
	return (name_);
}

unsigned int	DiamondTrap::init_hit_points(void)
{
	return (FragTrap::init_hit_points());
}

unsigned int	DiamondTrap::init_energy_points(void)
{
	return (ScavTrap::init_energy_points());
}

unsigned int	DiamondTrap::init_attack_damage(void)
{
	return (FragTrap::init_attack_damage());
}

const char*	DiamondTrap::class_name(void) const
{
	return ("DiamondTrap");
}

