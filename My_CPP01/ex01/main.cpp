#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie*		zombieHorde(int N, std::string name);
static int	validate_input(int argc, char *argv[], int& zombie_num, std::string& name);
static int	validate_parameter(char *argv[], int& zombie_num, std::string& name);

int	main(int argc, char *argv[])
{
	int			zombie_num;
	std::string	name;

	if (validate_input(argc, argv, zombie_num, name) == -1)
		return (1);
	try
	{
		Zombie*	zombie_arr = zombieHorde(zombie_num, name);
		for (int i = 0; i < zombie_num; i++)
			zombie_arr[i].announce();
		delete[] zombie_arr;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}

static int	validate_input(int argc, char *argv[], int& zombie_num, std::string& name)
{
	if (argc != 3)
	{
		std::cerr << argv[0] << " <number of zombie> <zombie's name>" << std::endl;
		return (-1);
	}
	return (validate_parameter(argv, zombie_num, name));
}

static int	validate_parameter(char *argv[], int& zombie_num, std::string& name)
{
	std::stringstream			ss(argv[1]);
	static const std::string	spaces = " \t\n\r\f\v";

	if (!(ss >> zombie_num) || zombie_num < 0)
	{
		std::cerr << "enter valid number" << std::endl;
		return (-1);
	}
	name = argv[2];
	if (name.empty() || name.find_first_not_of(spaces) == std::string::npos)
	{
		std::cerr << "enter valid zombie name" << std::endl;
		return (-1);
	}
	return (0);
}
