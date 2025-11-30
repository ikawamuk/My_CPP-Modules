#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
:Animal("Cat"), brain_p_(new Brain())
{
	std::cout << YELLOW;
	std::cout << "Cat default constructor was called!" << std::endl;
	std::cout << RESET;
}

Cat::Cat(const Cat& other)
:Animal(other), brain_p_(new Brain(*other.brain_p_))
{
	std::cout << YELLOW;
	std::cout << "Cat copy constructor was called!" << std::endl;
	std::cout << RESET;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*brain_p_ = *rhs.brain_p_;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << YELLOW;
	std::cout << "Cat destructor was called!" << std::endl;
	std::cout << RESET;
	delete brain_p_;
}

void	Cat::makeSound(void) const
{
	std::cout << "meow" << "...(" << brain_p_->get_newst_idea() << ")" << std::endl;
	return ;
}

void	Cat::think(const std::string& idea)
{
	brain_p_->add_idea(idea);
	return ;
}
