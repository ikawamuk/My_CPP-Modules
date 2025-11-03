#include "ClapTrap.hpp"
#include <iostream>
#include <sstream>

static const std::string	DELIMINATER(50, '-');

void	constructor_destructor_test(void)
{
	std::cout << RESET << DELIMINATER <<std::endl;
	std::cout << " const/destructor and attack test " << std::endl;
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ClapTrap	hoge;

		hoge.attack("Enemy1");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ClapTrap	hoge("Uma Thurman");

		hoge.attack("Enemy2");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ClapTrap	hoge("Samuel L. Jackson");
		ClapTrap	fuga;

		fuga = hoge;
		fuga.attack("Enemy3");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ClapTrap	hoge("Maria de Medeiros");
		ClapTrap	fuga(hoge);

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
		ClapTrap	hoge;

		hoge.takeDamage(9);
		hoge.attack("Enemy1");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ClapTrap	hoge;

		hoge.takeDamage(10);
		hoge.attack("Enemy2");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ClapTrap	hoge;

		hoge.takeDamage(15);
		hoge.attack("Enemy2");
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		ClapTrap	hoge;

		hoge.beRepaired(6);
		hoge.takeDamage(15);
		hoge.attack("Enemy3");
		hoge.takeDamage(1);
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
		ClapTrap	hoge;

		for (int i = 1; i <= 13; i++)
		{
			std::ostringstream oss;
			oss << "Enemy" << i;
			hoge.attack(oss.str());
		}
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
	return (0);
}
