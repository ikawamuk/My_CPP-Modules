#include "Cat.hpp"
#include <iostream>

Cat::Cat(const std::string& type)
:Animal(type)
{
	std::cout << "the Cat default constructor called!!" << std::endl;
	brain_ = new Brain();
	return ;
}

Cat::Cat(const Cat& other)
:Animal(other)
{
	std::cout << "the Cat copy constructor called!!" << std::endl;
	brain_ = new Brain();
	return ;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		brain_ = rhs.brain_;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "the Cat destructor called!!" << std::endl;
	delete brain_;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
	return ;
}

Brain&	Cat::brain(void)
{
	return (*brain_);
}
