#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
:ClapTrap(name + "_ClapTrap")
,name_(name)
{
	std::cout << GREEN << "the Diamond default constructor called!!" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
:ClapTrap(other)
{
	std::cout << GREEN << "the Diamond copy constructor called!!" << std::endl;
	return ;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << RESET << "the Diamond assignment operator called!!" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BLUE << "the Diamond destructor called!!" << std::endl;
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << WHITE;
	std::cout << "My name is " << name_;
	std::cout << " and my ClapTrap name is " << name() << std::endl;
	return ;
}
