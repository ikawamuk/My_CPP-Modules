#include "Brain.hpp"
#include <iostream>

Brain::Brain(std::string str)
:string(str)
,stringPTR(&string)
,stringREF(string)
{}

void	Brain::print_memory(void) const
{
	std::cout << &string << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	return ;
}

void	Brain::print_value(void) const
{
	std::cout << string << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return ;
}
