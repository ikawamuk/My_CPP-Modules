#include "TrapFactory.hpp"
#include "Trap.hpp"
#include "Name.hpp"
#include "HitPoints.hpp"
#include "EnergyPoints.hpp"
#include "AttackDamage.hpp"

TrapFactory::~TrapFactory()
{}

Trap*	TrapFactory::make(const std::string& input) const
{
	Name			name(input);
	HitPoints		hit_points(set_initial_hit_points());
	EnergyPoints	energy_points(set_initial_energy_points());
	Attackdamage	attack_damage(set_initial_attack_damage());

	return (generate_object(name, hit_points, energy_points, attack_damage));
}
