#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
:type_("WrongAnimal")
{
	std::cout << RED;
	std::cout << "WrongAnimal default constructor was called!" << std::endl;
	std::cout << RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
:type_(other.type_)
{
	std::cout << RED;
	std::cout << "WrongAnimal copy constructor was called!" << std::endl;
	std::cout << RESET;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this != &rhs)
		type_ = rhs.type_;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED;
	std::cout << "WrongAnimal destructor was called!" << std::endl;
	std::cout << RESET;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "An wronganimal made a sound." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (type_);
}

WrongAnimal::WrongAnimal(const std::string& type)
:type_(type)
{
	std::cout << RED;
	std::cout << "WrongAnimal parameterized constructor was called!" << std::endl;
	std::cout << RESET;
}
