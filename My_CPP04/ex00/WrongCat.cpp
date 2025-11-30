#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
:WrongAnimal("WrongCat")
{
	std::cout << YELLOW;
	std::cout << "WrongCat default constructor was called!" << std::endl;
	std::cout << RESET;
}

WrongCat::WrongCat(const WrongCat& other)
:WrongAnimal(other)
{
	std::cout << YELLOW;
	std::cout << "WrongCat copy constructor was called!" << std::endl;
	std::cout << RESET;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW;
	std::cout << "WrongCat destructor was called!" << std::endl;
	std::cout << RESET;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
