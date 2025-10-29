#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie*	new_zombie_p = new Zombie(name);

	return (new_zombie_p);
}
