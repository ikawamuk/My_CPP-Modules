#include "ClapTrap.hpp"
#include "Name.hpp"
#include <iostream>

ClapTrap::ClapTrap(const Name& name)
:name_(name), hit_points_(init_hit_points()), energy_points_(init_energy_points()), attack_damage_(init_attack_damage())
{
	std::cout << BLUE;
	std::cout << "Clap parameterized constructorcalled!";
	std::cout << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
:name_(other.name_), hit_points_(other.hit_points_), energy_points_(other.energy_points_), attack_damage_(other.attack_damage_)
{
	std::cout << BLUE;
	std::cout << "Clap copy constructor called!";
	std::cout << RESET << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		name_ = rhs.name_;
		hit_points_ = rhs.hit_points_;
		energy_points_ = rhs.energy_points_;
		attack_damage_ = rhs.attack_damage_;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << BLACK;
	std::cout << "Clap destructor called!";
	std::cout << RESET << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!can_take_action())
		return ;
	energy_points_--;
	std::cout << YELLOW;
	std::cout << class_name() << " " << name() << " attacks " << target;
	std::cout << ", causing " << attack_damage() << " points of damage!";
	std::cout << RESET << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	HitPoints	prev_hp(hit_points());

	hit_points_ -= amount;
	std::cout << RED;
	std::cout << class_name() << " " << name();
	std::cout << " has taken "<< prev_hp - hit_points() << " points of damage! ";
	if (!hit_points_)
		std::cout << name() << " has died...";
	else
		std::cout << "HP: " << hit_points();
	std::cout << RESET << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!can_take_action())
		return ;
	energy_points_--;
	hit_points_ += amount;
	std::cout << GREEN;
	std::cout << class_name() << " " << name() << " is repaired ";
	std::cout << amount << " points!" << " HP: " << hit_points();
	std::cout << RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(void)
{
	std::cout << BLUE;
	std::cout << "Clap default constructor called!" << std::endl;
	std::cout << RESET;
}

const Name&	ClapTrap::name(void) const
{
	return (name_);
}

const HitPoints&	ClapTrap::hit_points(void) const
{
	return (hit_points_);
}

const EnergyPoints&	ClapTrap::energy_points(void) const
{
	return (energy_points_);
}

const AttackDamage&	ClapTrap::attack_damage(void) const
{
	return (attack_damage_);
}

unsigned int	ClapTrap::init_hit_points(void)
{
	return (10);
}

unsigned int	ClapTrap::init_energy_points(void)
{
	return (10);
}

unsigned int	ClapTrap::init_attack_damage(void)
{
	return (0);
}

const char*	ClapTrap::class_name(void) const
{
	return ("ClapTrap");
}

bool	ClapTrap::can_take_action(void) const
{
	if (hit_points() && energy_points())
		return (true);
	if (!hit_points())
		std::cout << class_name() << " " << name() << " is dead... He can't take any actioin." << std::endl;
	else if (!energy_points())
		std::cout << class_name() << " " << name() << " has no energy points... He can't take any actioin." << std::endl;
	return (false);
}
