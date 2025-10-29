#include "Zombie.hpp"
#include <iostream>

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	harry("Harry");

	harry.announce();
	randomChump("Hermione");
	try
	{
		Zombie*	you_know_who = newZombie("you_know_who");
		you_know_who->announce();
		delete you_know_who;
	}
	catch (std::exception &e)
	{
		std::cerr << "braiiiiiiinnnzzzZ: " << e.what() << std::endl;
	}
	return (0);
}
