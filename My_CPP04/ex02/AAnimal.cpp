#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(const std::string& type)
:type_(type)
{
	std::cout << "the AAnimal default constructor called!!" << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal& other)
:type_(other.type_)
{
	std::cout << "the AAnimal copy constructor called!!" << std::endl;
	return ;
}

AAnimal&	AAnimal::operator=(const AAnimal& rhs)
{
	if (this != &rhs)
		type_ = rhs.type_;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "the AAnimal destructor called!!" << std::endl;
	return ;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "An aanimal made a sound." << std::endl;
	return ;
}

const std::string&	AAnimal::getType(void) const
{
	return (type_);
}