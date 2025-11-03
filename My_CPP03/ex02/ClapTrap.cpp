#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap(const std::string& name,int hit_points, int energy_points, int attack_damage)
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
	int prev_hp = hit_points_;
	hit_points_ = static_cast<unsigned int>(hit_points_) > amount ? hit_points_ - amount : 0;

	std::cout << YELLOW;
	std::cout << name_ << " takes "<< prev_hp - hit_points_<< " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned long	CASTED_INT_MAX = static_cast<unsigned long>(std::numeric_limits<int>::max());
	unsigned long	new_hp = static_cast<unsigned long>(hit_points_) + static_cast<unsigned long>(amount);

	if (!can_take_action())
		return ;
	energy_points_--;
	hit_points_ = new_hp < CASTED_INT_MAX ? static_cast<int>(new_hp) : std::numeric_limits<int>::max();
	std::cout << YELLOW;
	std::cout << name_ << " is repaired "<< amount << " points.";
	std::cout << "Current HP: " << hit_points_ << std::endl;
	return ;
}

const std::string&	ClapTrap::name(void)
{
	return (name_);
}

int	ClapTrap::hit_points(void) const
{
	return (hit_points_);
}

int	ClapTrap::energy_points(void) const
{
	return (energy_points_);
}

int	ClapTrap::attack_damage(void) const
{
	return (attack_damage_);
}

void	ClapTrap::set_hit_points(int hit_points)
{
	hit_points_ = hit_points > 0 ? hit_points : 0;
	return ;
}

void	ClapTrap::set_energy_points(int energy_points)
{
	energy_points_ = energy_points > 0 ? energy_points : 0;
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
