#include "ClapTrapFactory.hpp"
#include "ClapTrap.hpp"
#include "Name.hpp"
#include "HitPoints.hpp"
#include "EnergyPoints.hpp"
#include "AttackDamage.hpp"

ClapTrapFactory::~ClapTrapFactory()
{}

ClapTrap* ClapTrapFactory::make(const std::string& input) const
{
	return static_cast<ClapTrap*>(TrapFactory::make(input));
}

ClapTrap*	ClapTrapFactory::generate_object(const Name& name, const HitPoints& hp, const EnergyPoints& ep, const Attackdamage& ad) const
{
	return (new ClapTrap(name, hp, ep, ad));
}

unsigned int	ClapTrapFactory::set_initial_hit_points() const
{
	return (10);
}
unsigned int	ClapTrapFactory::set_initial_energy_points() const
{
	return (10);
}

unsigned int	ClapTrapFactory::set_initial_attack_damage() const
{
	return (0);
}