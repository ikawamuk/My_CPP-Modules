#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
:Animal("Dog"), brain_p_(new Brain())
{
	std::cout << GREEN;
	std::cout << "Dog default constructor was called!" << std::endl;
	std::cout << RESET;
}

Dog::Dog(const Dog& other)
:Animal(other), brain_p_(new Brain(*other.brain_p_))
{
	std::cout << GREEN;
	std::cout << "Dog copy constructor was called!" << std::endl;
	std::cout << RESET;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*brain_p_ = *rhs.brain_p_;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << GREEN;
	std::cout << "Dog destructor was called!" << std::endl;
	std::cout << RESET;
	delete brain_p_;
}

void	Dog::makeSound(void) const
{
	std::cout << "bow wow" << "...(" << brain_p_->get_newst_idea() << ")" << std::endl;
	return ;
}

void	Dog::think(const std::string& idea)
{
	brain_p_->add_idea(idea + "!");
	return ;
}
