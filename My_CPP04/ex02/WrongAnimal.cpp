#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(const std::string& type)
:type_(type)
{
	std::cout << "the WrongAnimal default constructor called!!" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
:type_(other.type_)
{
	std::cout << "the WrongAnimal copy constructor called!!" << std::endl;
	return ;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this != &rhs)
		type_ = rhs.type_;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "the WrongAnimal destructor called!!" << std::endl;
	return ;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "An WrongAnimal made a sound." << std::endl;
	return ;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (type_);
}