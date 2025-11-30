#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
:WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor was called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
:WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor was called!" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor was called!" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
