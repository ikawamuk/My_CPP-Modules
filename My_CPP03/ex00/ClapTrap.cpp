#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap(const std::string& name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage)
:name_(name)
,hit_points_(hit_points)
,energy_points_(energy_points)
,attack_damage_(attack_damage)
{
	std::cout << GREEN << "the Clap default constructor called!!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& other)
:name_(other.name_)
,hit_points_(other.hit_points_)
,energy_points_(other.energy_points_)
,attack_damage_(other.attack_damage_)
{
	std::cout << GREEN << "the Clap copy constructor called!!" << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << RESET << "the Clap assignment operator called!!" << std::endl;
	if (this != &rhs)
	{
		name_ = rhs.name_;
		attack_damage_ = rhs.attack_damage_;
		hit_points_ = rhs.hit_points_;
		energy_points_ = rhs.energy_points_;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << BLUE << "the Clap destructor called!!" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!can_take_action())
		return ;
	energy_points_--;
	std::cout << YELLOW;
	std::cout << "ClapTrap "<< name_ \
			<< " attacks "<< target \
			<< ", causing "<< attack_damage_ << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	long prev_hp = hit_points_;
	hit_points_ = hit_points_ > amount ? static_cast<long>(hit_points_) - static_cast<long>(amount) : 0;
	std::cout << YELLOW;
	std::cout << name_ << " takes "<< prev_hp - hit_points_<< " points of damage! ";
	std::cout << "Current HP: " << hit_points_ << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned long	CASTED_INT_MAX = static_cast<unsigned long>(std::numeric_limits<unsigned int>::max());
	unsigned long	new_hp = static_cast<unsigned long>(hit_points_) + static_cast<unsigned long>(amount);

	if (!can_take_action())
		return ;
	energy_points_--;
	hit_points_ = new_hp < CASTED_INT_MAX ? static_cast<unsigned int>(new_hp) : std::numeric_limits<unsigned int>::max();
	std::cout << YELLOW;
	std::cout << name_ << " is repaired "<< amount << " points. ";
	std::cout << "Current HP: " << hit_points_ << std::endl;
	return ;
}

bool	ClapTrap::can_take_action(void) const
{
	if (hit_points_ == 0)
	{
		std::cout << RED << name_ << " has no hit points left! it can't take anymore action..." << std::endl;
		return (false);
	}
	if (energy_points_ == 0)
	{
		std::cout << RED << name_ << " has no energy points left! it can't take anymore action..." << std::endl;
		return (false);
	}
	return (true);
}
