#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
:Animal("Cat")
{
	std::cout << YELLOW;
	std::cout << "Cat default constructor was called!" << std::endl;
	std::cout << RESET;
}

Cat::Cat(const Cat& other)
:Animal(other)
{
	std::cout << YELLOW;
	std::cout << "Cat copy constructor was called!" << std::endl;
	std::cout << RESET;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
		Animal::operator=(rhs);
	return (*this);
}

Cat::~Cat()
{
	std::cout << YELLOW;
	std::cout << "Cat destructor was called!" << std::endl;
	std::cout << RESET;
}

void	Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
