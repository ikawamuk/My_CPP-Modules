#include "ClapTrap.hpp"
#include <iostream>
#include <sstream>
#include <memory>

std::auto_ptr<ClapTrap>	generate_new_trap(void);

// for ScavTrap

void	attack_test(void)
{
	std::cout << "attack test" << std::endl;
	std::auto_ptr<ClapTrap> trap = generate_new_trap();
	trap->attack("Target1");
	trap->attack("Target2");
}

void	take_damage_test(void)
{
	std::cout << "takeDamage test1" << std::endl;
	std::auto_ptr<ClapTrap> trap = generate_new_trap();
	trap->takeDamage(99);
	trap->attack("Target1");
	trap->takeDamage(1);
	trap->attack("Target2");
}

void	take_zero_and_over_damage_test(void)
{
	std::cout << "take zero and over damage test" << std::endl;
	std::auto_ptr<ClapTrap> trap = generate_new_trap();
	trap->takeDamage(0);
	trap->attack("Target1");
	trap->takeDamage(150);
	trap->attack("Target2");
}

void	be_repaired_test(void)
{
	std::cout << "beRepaired test" << std::endl;
	std::auto_ptr<ClapTrap> trap = generate_new_trap();
	trap->beRepaired(1);
	trap->takeDamage(100);
	trap->attack("Target1");
	trap->takeDamage(1);
	trap->attack("Target2");
}

void	energy_points_test(void)
{
	std::cout << "energy points tests" << std::endl;
	std::auto_ptr<ClapTrap> trap = generate_new_trap();
	for (int i = 0; i < 103; i++)
	{
		std::ostringstream oss;
		oss << "Target" << i;
		trap->attack(oss.str());
	}
	return ;
}

#include "ScavTrap.hpp"
void	scav_special_ability_test(void)
{
	std::cout << "Scav special ability tests" << std::endl;
	std::auto_ptr<ClapTrap> trap = generate_new_trap();
	ScavTrap*	scav = dynamic_cast<ScavTrap*>(trap.get());
	if (scav)
		scav->guardGate();
	else
		std::cout << "He is not ScavTrap." << std::endl;
	return ;
}

#include "FragTrap.hpp"
void	frag_special_ability_test(void)
{
	std::cout << "Frag special ability tests" << std::endl;
	std::auto_ptr<ClapTrap> trap = generate_new_trap();
	FragTrap*	frag = dynamic_cast<FragTrap*>(trap.get());
	if (frag)
		frag->highFivesGuys();
	else
		std::cout << "He is not FragTrap." << std::endl;
	return ;
}

void	any_case_what_you_want(void)
{
	std::cout << "Any case what you want?" << std::endl;
	// std::auto_ptr<ClapTrap> trap = generate_new_trap();

	return ;
}

void	trap_test(void)
{
	
	attack_test();
	std::cout << std::endl;
	take_damage_test();
	std::cout << std::endl;
	take_zero_and_over_damage_test();
	std::cout << std::endl;
	be_repaired_test();
	std::cout << std::endl;
	energy_points_test();
	std::cout << std::endl;
	scav_special_ability_test();
	std::cout << std::endl;
	frag_special_ability_test();
	std::cout << std::endl;
	any_case_what_you_want();
	return ;
}
