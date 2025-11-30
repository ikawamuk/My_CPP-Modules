#include "Floor.hpp"
#include "debug_mode.hpp"
#include "print_color.hpp"
#include <cstring>

Floor::Floor(void)
:current_idx_(0)
{
	PRINT_DEBUG(CYAN << "Floor constructor called!" << RESET)
	std::memset(stock_, 0, sizeof(stock_));
}

Floor::~Floor()
{
	PRINT_DEBUG(BLACK << "Floor destructor called!" << RESET)
	clear();
}

void	Floor::drop(AMateria* new_one)
{
	PRINT_DEBUG("a materia was dropped on the floor")
	if (!new_one)
		return ;
	delete stock_[current_idx_];
	stock_[current_idx_] = new_one;
	current_idx_ = (current_idx_ + 1)% STOCK_SIZE;
	return ;
}

void	Floor::clear(void)
{
	PRINT_DEBUG("the floor was cleared")
	for (int i = 0; i < STOCK_SIZE; i++)
	{
		delete stock_[i];
		stock_[i] = 0;
	}
	return ;
}

Floor::Floor(const Floor& other)
{
	std::memset(stock_, 0, sizeof(stock_));
	current_idx_ = other.current_idx_;
	for (int i = 0; i < STOCK_SIZE; i++)
	{
		if (other.stock_[i])
			stock_[i] = other.stock_[i]->clone();
	}
}

Floor&	Floor::operator=(const Floor& rhs)
{
	if (this != &rhs)
	{
		current_idx_ = rhs.current_idx_;
		clear();
		for (int i = 0; i < STOCK_SIZE; i++)
		{
			if (rhs.stock_[i])
				stock_[i] = rhs.stock_[i]->clone();
		}
	}
	return (*this);
}
