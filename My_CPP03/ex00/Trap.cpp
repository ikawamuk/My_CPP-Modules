#include "Trap.hpp"
#include <iostream>

Trap::Trap(Name name, HitPoints hit_points, EnergyPoints energy_points, Attackdamage attack_damage)
:name_(name), hit_points_(hit_points), energy_points_(energy_points), attack_damage_(attack_damage)
{}

Trap::Trap(const Trap& other)
:name_(other.name_), hit_points_(other.hit_points_), energy_points_(other.energy_points_), attack_damage_(other.attack_damage_)
{}

Trap&	Trap::operator=(const Trap& rhs)
{
	if (this != &rhs)
	{
		name_ = rhs.name_;
		hit_points_ = rhs.hit_points_;
		energy_points_ = rhs.energy_points_;
		attack_damage_ = rhs.attack_damage_;
	}
	return *this;
}

Trap::~Trap()
{}

void	Trap::attack(const std::string& target)
{
	std::cout << class_name() << " " << name() << " attacks " << target;
	std::cout << ", causing " << attack_damage_ << " points of damage!" << std::endl;
	return ;
}

void	Trap::takeDamage(unsigned int amount)
{
	hit_points_ = hit_points_.decrease_value(amount);
	return ;
}

void	Trap::beRepaired(unsigned int amount)
{
	energy_points_ = energy_points_.decrement_value();
	hit_points_ = hit_points_.increase_value(amount);
	return ;
}

Trap::Trap(void)
:name_(), hit_points_(), energy_points_(), attack_damage_()
{}

const Name&	Trap::name(void) const
{
	return (name_);
}

const HitPoints& Trap::hit_points(void) const
{
	return (hit_points_);
}

const EnergyPoints& Trap::energy_points(void) const
{
	return (energy_points_);
}

const Attackdamage& Trap::attack_damage(void) const
{
	return (attack_damage_);
}

const std::string	Trap::class_name(void) const
{
	return ("Trap");
}