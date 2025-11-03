#include "Dog.hpp"
#include <iostream>

Dog::Dog(const std::string& type)
:Animal(type)
{
	std::cout << "the Dog default constructor called!!" << std::endl;
}

Dog::Dog(const Dog& other)
:Animal(other)
{
	std::cout << "the Dog copy constructor called!!" << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "the Dog destructor called!!" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "bow-wow" << std::endl;
	return ;
}
