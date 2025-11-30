#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
:type_("Animal")
{
	std::cout << RED;
	std::cout << "Animal default constructor was called!" << std::endl;
	std::cout << RESET;
}

Animal::Animal(const Animal& other)
:type_(other.type_)
{
	std::cout << RED;
	std::cout << "Animal copy constructor was called!" << std::endl;
	std::cout << RESET;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	if (this != &rhs)
		type_ = rhs.type_;
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED;
	std::cout << "Animal destructor was called!" << std::endl;
	std::cout << RESET;
}

std::string	Animal::getType(void) const
{
	return (type_);
}

Animal::Animal(const std::string& type)
:type_(type)
{
	std::cout << RED;
	std::cout << "Animal parameterized was called!" << std::endl;
	std::cout << RESET;
}
