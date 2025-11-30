#include "Ice.hpp"
#include "debug_mode.hpp"
#include "print_color.hpp"
#include <iostream>

Ice::Ice(void)
:AMateria(type_name())
{
	PRINT_DEBUG(YELLOW << "Ice parameterized constructor called!" << RESET)
}

Ice::Ice(const Ice& other)
:AMateria(other)
{
	PRINT_DEBUG(YELLOW << "Ice copy constructor called!" << RESET)
}

Ice&	Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

Ice::~Ice()
{
	PRINT_DEBUG(BLACK << "Ice destructor called!" << RESET)
}

AMateria* Ice::clone() const
{
	PRINT_DEBUG("Ice cloned")
	return (new Ice(*this));
}

std::string	Ice::type_name(void) const
{
	return ("ice");
}

void	Ice::put_message(const std::string& name) const
{
	std::cout << "* shoots an ice bolt at " << name << " *" << std::endl;
	return ;
}
