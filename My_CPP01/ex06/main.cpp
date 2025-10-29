#include "Harl.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc != 2)
	{
		std::cerr << argv[0] << " <label>" << std::endl;
		return (1);
	}
	harl.filter(std::string(argv[1]));
	return (0);
}
