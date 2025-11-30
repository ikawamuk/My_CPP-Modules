#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "debug_mode.hpp"
#include "print_color.hpp"
#include <iostream>
#include <exception>

AMateria::AMateria(const std::string& type)
:type_(type)
{
	PRINT_DEBUG(RED << "AMateria parameterized constructor called!" << RESET)
}

AMateria::AMateria(const AMateria& other)
:type_(other.type_)
{
	PRINT_DEBUG(RED << "AMateria copy constructor called!" << RESET)
}

AMateria::~AMateria()
{
	PRINT_DEBUG(BLACK << "AMateria destructor called!" << RESET)
}

const std::string&	AMateria::getType(void) const
{
	return (type_);
}

void	AMateria::use(ICharacter& target)
{
	PRINT_DEBUG("AMateria is used to " << target.getName())
	put_message(target.getName());
	return ;
}

AMateria::AMateria(void)
{
	PRINT_DEBUG(RED << "AMateria default constructor called!" << RESET)
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	(void)rhs;
	return (*this);
}
