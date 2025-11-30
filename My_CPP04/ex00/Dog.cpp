#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
:Animal("Dog")
{
	std::cout << GREEN;
	std::cout << "Dog default constructor was called!" << std::endl;
	std::cout << RESET;
}

Dog::Dog(const Dog& other)
:Animal(other)
{
	std::cout << GREEN;
	std::cout << "Dog copy constructor was called!" << std::endl;
	std::cout << RESET;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

Dog::~Dog()
{
	std::cout << GREEN;
	std::cout << "Dog destructor was called!" << std::endl;
	std::cout << RESET;
}

void	Dog::makeSound(void) const
{
	std::cout << "bow wow" << std::endl;
}
