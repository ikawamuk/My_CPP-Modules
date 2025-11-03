#include "DiamondTrap.hpp"
#include <iostream>

static const std::string	DELIMINATER(50, '-');

void	test(void)
{

	return ;
}

void	special_ability_test(void)
{
	std::cout << RESET << DELIMINATER <<std::endl;
	std::cout << " special ability test " << std::endl;
	std::cout << RESET << DELIMINATER <<std::endl;
	{
		DiamondTrap	hoge;

		hoge.guardGate();
		hoge.highFivesGuys();
		hoge.whoAmI();
	}
	std::cout << RESET << DELIMINATER <<std::endl;
	return ;
}

int	main(void)
{
	test();
	special_ability_test();
	return (0);
}
