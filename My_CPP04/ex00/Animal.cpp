#include "Animal.hpp"
#include <iostream>

Animal::Animal(const std::string& type)
:type_(type)
{
	std::cout << "the Animal default constructor called!!" << std::endl;
}

Animal::Animal(const Animal& other)
:type_(other.type_)
{
	std::cout << "the Animal copy constructor called!!" << std::endl;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
		type_ = rhs.type_;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "the Animal destructor called!!" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "An animal made a sound." << std::endl;
	return ;
}

const std::string&	Animal::getType(void) const
{
	return (type_);
}