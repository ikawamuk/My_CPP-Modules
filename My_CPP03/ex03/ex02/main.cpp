#include "FragTrap.hpp"
#include <iostream>
#include <sstream>

static const std::string	DELIMINATER(50, '-');

void	constructor_destructor_test(void)
{
	std::cout << RESET << DELIMINATER <<std::endl;
	std::cout << " const/destructor and attack test " << std::endl;
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		FragTrap	hoge;

		hoge.attack("Enemy1");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		FragTrap	hoge("Uma Thurman");

		hoge.attack("Enemy2");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		FragTrap	hoge("Samuel L. Jackson");
		FragTrap	fuga;

		fuga = hoge;
		fuga.attack("Enemy3");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		FragTrap	hoge("Maria de Medeiros");
		FragTrap	fuga(hoge);

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
		FragTrap	hoge;

		hoge.takeDamage(99);
		hoge.attack("Enemy1");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		FragTrap	hoge;

		hoge.takeDamage(100);
		hoge.attack("Enemy2");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		FragTrap	hoge;

		hoge.takeDamage(150);
		hoge.attack("Enemy2");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		FragTrap	hoge;

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
		FragTrap	hoge;

		for (int i = 1; i <= 103; i++)
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
		FragTrap	hoge;
		FragTrap	fuga("Walter Bruce Willis");

		hoge.highFivesGuys();
		fuga.highFivesGuys();
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
