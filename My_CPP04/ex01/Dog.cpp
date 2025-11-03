#include "Dog.hpp"
#include <iostream>

Dog::Dog(const std::string& type)
:Animal(type)
{
	std::cout << "the Dog default constructor called!!" << std::endl;
	brain_ = new Brain();
	return ;
}

Dog::Dog(const Dog& other)
:Animal(other)
{
	std::cout << "the Dog copy constructor called!!" << std::endl;
	brain_ = new Brain();
	return ;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		brain_ = rhs.brain_;
	}
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

Brain&	Dog::brain(void)
{
	return (*brain_);
}
