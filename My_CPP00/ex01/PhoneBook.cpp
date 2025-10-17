#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>

PhoneBook::PhoneBook(void){}

void	PhoneBook::run(void)
{
	std::string	input;

	try
	{
		while (1)
		{
			read_input("Input command (ADD, SEARCH, EXIT): ", input);
			if (input == "ADD")
				add();
			else if (input == "SEARCH")
				search();
			else if (input == "EXIT")
				break ;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "PhoneBook: " << e.what() << std::endl;
	}
	return ;
}

void	PhoneBook::read_input(const std::string& prompt, std::string& input)
{
	std::cout << prompt;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		throw std::runtime_error("recieved EOF");
	}
	return ;
}
