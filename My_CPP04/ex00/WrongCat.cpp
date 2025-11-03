#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(const std::string& type)
:WrongAnimal(type)
{
	std::cout << "the WrongCat default constructor called!!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
:WrongAnimal(other)
{
	std::cout << "the WrongCat copy constructor called!!" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "the WrongCat destructor called!!" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
	return ;
}
