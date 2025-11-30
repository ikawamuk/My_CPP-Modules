#include "Character.hpp"
#include "Floor.hpp"
#include "debug_mode.hpp"
#include "print_color.hpp"
#include <cstring>

Floor Character::floor;

Character::Character(const std::string& name)
:name_(name)
{
	PRINT_DEBUG(BLUE << "Character parameterized constructor called!" << RESET)
	std::memset(inventory_, 0, sizeof(inventory_));
}

Character::Character(const Character& other)
:name_(other.name_)
{
	PRINT_DEBUG(BLUE << "Character copy constructor called!" << RESET)
	std::memset(inventory_, 0, sizeof(inventory_));
	copy_inventory(other);
}

Character&	Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		name_ = rhs.name_;
		delete_inventory();
		copy_inventory(rhs);
	}
	return (*this);
}

Character::~Character()
{
	PRINT_DEBUG(BLACK << "Character destructor called!" << RESET)
	delete_inventory();
}

const std::string&	Character::getName() const
{
	return (name_);
}

void	Character::equip(AMateria* m)
{
	PRINT_DEBUG("Character equip a materia!")
	for (int i = 0; i < SLOT_SIZE; ++i)
	{
		if (inventory_[i] == m)
			return;
	}
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (inventory_[i] == 0)
		{
			inventory_[i] = m;
			return;
		}
	}
	floor.drop(m);
	return ;
}

void	Character::unequip(int idx)
{
	PRINT_DEBUG("Character unequip the materia" << idx)
	if (0 <= idx && idx < SLOT_SIZE && inventory_[idx])
	{
		floor.drop(inventory_[idx]);
		inventory_[idx] = 0;
	}
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	PRINT_DEBUG("Character use the materia" << idx)
	if (0 <= idx && idx < SLOT_SIZE && inventory_[idx])
		inventory_[idx]->use(target);
	return ;
}

Character::Character(void)
{
	PRINT_DEBUG(BLUE << "Character default constructor called!" << RESET)
}

void	Character::delete_inventory(void)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		delete inventory_[i];
		inventory_[i] = 0;
	}
	return ;
}

void	Character::copy_inventory(const Character& src)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (src.inventory_[i])
			inventory_[i] = src.inventory_[i]->clone();
		else
			inventory_[i] = 0;
	}
	return ;
}
