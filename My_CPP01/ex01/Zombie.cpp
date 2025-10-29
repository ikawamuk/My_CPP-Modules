#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
:name()
{}

Zombie::~Zombie(void)
{
	std::cout << "destroyed " << name << std::endl;
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::set_name(std:: string name)
{
	this->name = name;
	return ;
}
