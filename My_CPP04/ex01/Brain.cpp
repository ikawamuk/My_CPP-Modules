#include "Brain.hpp"
#include <iostream>

Brain::Brain(const std::string& idea)
{
	std::cout << BLUE;
	std::cout << "Brain default constructor called!" << std::endl;
	std::cout << RESET;
	for (int i = 0; i < IDEAS_SIZE; i++)
		ideas_[i] = idea;
	newest_idea_index = IDEAS_SIZE - 1;
}

Brain::Brain(const Brain& other)
{
	std::cout << BLUE;
	std::cout << "Brain copy constructor called!" << std::endl;
	std::cout << RESET;
	for (int i = 0; i < IDEAS_SIZE; ++i)
		ideas_[i] = other.ideas_[i];
	newest_idea_index = other.newest_idea_index;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < IDEAS_SIZE; ++i)
			ideas_[i] = rhs.ideas_[i];
		newest_idea_index =  rhs.newest_idea_index;
	}
	return (*this);
}

const std::string&	Brain::operator[](std::size_t i) const
{
	return (ideas_[i]);
}

Brain::~Brain()
{
	std::cout << BLUE;
	std::cout << "Brain destructor called!" << std::endl;
	std::cout << RESET;
}

void	Brain::add_idea(const std::string& idea)
{
	newest_idea_index = (newest_idea_index + 1) % IDEAS_SIZE;
	ideas_[newest_idea_index] = idea;
	return ;
}

const std::string	Brain::get_newst_idea(void) const
{
	return (ideas_[newest_idea_index]);
}
