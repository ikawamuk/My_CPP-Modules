#include "Dog.hpp"
#include <iostream>

Dog::Dog(const std::string& type)
:AAnimal(type)
{
	std::cout << "the Dog default constructor called!!" << std::endl;
	brain_ = new Brain();
	return ;
}

Dog::Dog(const Dog& other)
:AAnimal(other)
{
	std::cout << "the Dog copy constructor called!!" << std::endl;
	brain_ = new Brain();
	return ;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
		AAnimal::operator=(rhs);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "the Dog destructor called!!" << std::endl;
	delete brain_;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "bow-wow" << std::endl;
	return ;
}
