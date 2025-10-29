#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	comment_table_[0].label = "DEBUG";
	comment_table_[0].member_func_p = &Harl::debug;
	comment_table_[1].label = "INFO";
	comment_table_[1].member_func_p = &Harl::info;
	comment_table_[2].label = "WARNING";
	comment_table_[2].member_func_p = &Harl::warning;
	comment_table_[3].label = "ERROR";
	comment_table_[3].member_func_p = &Harl::error;
	return ;
}

void	Harl::filter(std::string label)
{
	std::size_t	index;

	for (index = 0; index < TABLE_SIZE; index++)
		if (label == comment_table_[index].label)
			break ;
	if (index < TABLE_SIZE)
		std::cout << "[ " << label << " ]" << std::endl;
	switch (index)
	{
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		case (0):
			(this->*comment_table_[0].member_func_p)();
			/* fall through */
		case (1):
			(this->*comment_table_[1].member_func_p)();
			/* fall through */
		case (2):
			(this->*comment_table_[2].member_func_p)();
			/* fall through */
		case (3):
			(this->*comment_table_[3].member_func_p)();
			/* fall through */
	}
	return ;
}

void	Harl::complain(std::string label)
{
	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		if (label == comment_table_[i].label)
		{
			(this->*comment_table_[i].member_func_p)();
			return ;
		}
	}
	std::cerr << "Incalid ladel" << std::endl;
	return ;
}

void	Harl::debug(void)
{
	const std::string	DEBUG_MSG("message for DEBUG");

	std::cerr << DEBUG_MSG << std::endl;
	return ;
}

void	Harl::info(void)
{
	const std::string	INFO_MSG("message for INFO");

	std::cerr << INFO_MSG << std::endl;
	return ;
}

void	Harl::warning(void)
{
	const std::string	WARNING_MSG("message for WARNING");

	std::cerr << WARNING_MSG << std::endl;
	return ;
}

void	Harl::error(void)
{
	const std::string	ERROR_MSG("message for ERROR");

	std::cerr << ERROR_MSG << std::endl;
	return ;
}
