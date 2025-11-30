#include "MateriaSource.hpp"
#include "debug_mode.hpp"
#include "print_color.hpp"
#include <cstring>

MateriaSource::MateriaSource(void)
{
	PRINT_DEBUG(BLUE << "MateriaSource parameterized constructer called!" << RESET)
	std::memset(templates_, 0, sizeof(templates_));
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	PRINT_DEBUG(BLUE << "MateriaSource copy constructer called!" << RESET)
	std::memset(templates_, 0, sizeof(templates_));
	copy_stock(other);
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		delete_stock();
		copy_stock(rhs);
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	PRINT_DEBUG(BLACK << "MateriaSource destructer called!" << RESET)
	delete_stock();
}

void	MateriaSource::learnMateria(AMateria* m)
{
	PRINT_DEBUG("MateriaSource learn a materia!")
	if (!m)
		return ;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (templates_[i] == 0)
		{
			templates_[i] = m->clone();
			delete m;
			return;
		}
	}
	delete m;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	PRINT_DEBUG("MateriaSource create a materia!")
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (templates_[i] && templates_[i]->getType() == type)
			return (templates_[i]->clone());
	}
	return (0);
}

void	MateriaSource::delete_stock(void)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		delete templates_[i];
		templates_[i] = 0;
	}
	return ;
}

void	MateriaSource::copy_stock(const MateriaSource& src)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (src.templates_[i])
			templates_[i] = src.templates_[i]->clone();
	}
	return ;
}
