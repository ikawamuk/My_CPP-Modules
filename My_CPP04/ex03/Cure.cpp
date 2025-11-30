#include "Cure.hpp"
#include "debug_mode.hpp"
#include "print_color.hpp"
#include <iostream>

Cure::Cure(void)
:AMateria(type_name())
{
	PRINT_DEBUG(YELLOW << "Cure parameterized constructor called!" << RESET)
}

Cure::Cure(const Cure& other)
:AMateria(other)
{
	PRINT_DEBUG(YELLOW << "Cure copy constructor called!" << RESET)
}

Cure&	Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

Cure::~Cure()
{
	PRINT_DEBUG(BLACK << "Cure destructor called!" << RESET)
}

AMateria* Cure::clone() const
{
	PRINT_DEBUG("Cure cloned")
	return (new Cure(*this));
}

std::string	Cure::type_name(void) const
{
	return ("cure");
}

void	Cure::put_message(const std::string& name) const
{
	std::cout << "* heals " << name << "'s wounds *" << std::endl;
	return ;
}
