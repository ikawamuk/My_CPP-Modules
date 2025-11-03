#include "Brain.hpp"
#include <iostream>
#include <exception>

Brain::Brain(void)
{
	std::cout << "the Brain default constructor called!!" << std::endl;
	for (int i = 0; i < IDEAS_SIZE; i++)
		ideas_[i] = "no idea";
}

Brain::Brain(const Brain& other)
{
	std::cout << "the Brain copy constructor called!!" << std::endl;
	for (int i = 0; i < IDEAS_SIZE; i++)
		ideas_[i] = other.ideas_[i];
	return ;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < IDEAS_SIZE; i++)
			ideas_[i] = rhs.ideas_[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "the Brain destructor called!!" << std::endl;
	return ;
}

const std::string	(&Brain::ideas(void) const)[IDEAS_SIZE]
{
	return (ideas_);
}

void	Brain::set_ideas(const std::string* ideas)
{
	for (int i = 0; i < IDEAS_SIZE; i++)
		ideas_[i] = ideas[i];
	return ;
}

void	Brain::set_an_idea(const std::string idea, int index)
{
	if (index < 0 || IDEAS_SIZE <= index)
		throw std::out_of_range("index out of range of ideas");
	ideas_[index] = idea;
	return ;
}