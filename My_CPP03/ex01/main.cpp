#include "ScavTrap.hpp"
#include <iostream>
#include <sstream>

static const std::string	DELIMINATER(50, '-');

void	constructor_destructor_test(void)
{
	std::cout << RESET << DELIMINATER <<std::endl;
	std::cout << " const/destructor and attack test " << std::endl;
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge;

		hoge.attack("Enemy1");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge("Uma Thurman");

		hoge.attack("Enemy2");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge("Samuel L. Jackson");
		ScavTrap	fuga;

		fuga = hoge;
		fuga.attack("Enemy3");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge("Maria de Medeiros");
		ScavTrap	fuga(hoge);

		fuga.attack("Enemy4");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	return ;
}

void	hit_points_test(void)
{
	std::cout << RESET << DELIMINATER <<std::endl;
	std::cout << " hit points test " << std::endl;
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge;

		hoge.takeDamage(99);
		hoge.attack("Enemy1");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge;

		hoge.takeDamage(100);
		hoge.attack("Enemy2");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge;

		hoge.takeDamage(150);
		hoge.attack("Enemy2");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge;

		hoge.beRepaired(60);
		hoge.takeDamage(150);
		hoge.attack("Enemy3");
		hoge.takeDamage(10);
		hoge.attack("Enemy3");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	return ;
}

void	energy_points_test(void)
{
	std::cout << RESET << DELIMINATER <<std::endl;
	std::cout << " energy points test " << std::endl;
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge;

		for (int i = 1; i <= 53; i++)
		{
			std::ostringstream oss;
			oss << "Enemy" << i;
			hoge.attack(oss.str());
		}
	}
	std::cout << RESET << DELIMINATER <<std::endl;
}

void	special_ability_test(void)
{
	std::cout << RESET << DELIMINATER <<std::endl;
	std::cout << " special ability test " << std::endl;
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ScavTrap	hoge;
		ScavTrap	fuga("Walter Bruce Willis");

		hoge.guardGate();
		fuga.guardGate();
	}
	std::cout << RESET << DELIMINATER <<std::endl;
}

int	main(void)
{
	constructor_destructor_test();
	std::cout << std::endl;
	hit_points_test();
	std::cout << std::endl;
	energy_points_test();
	std::cout << std::endl;
	special_ability_test();
	return (0);
}
