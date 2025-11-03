#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "the Brain default constructor called!!" << std::endl;
	for (int i = 0; i < IDEAS_SIZE; i++)
		ideas_[i] = "no idea";
}

Brain::Brain(const Brain& other)
:ideas_(other.ideas_)
{
	std::cout << "the Brain copy constructor called!!" << std::endl;
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
