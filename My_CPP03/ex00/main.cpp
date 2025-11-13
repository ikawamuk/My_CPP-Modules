#include "ClapTrap.hpp"
#include "Name.hpp"
#include <memory>

void	trap_test(void);

int	main(void)
{
	trap_test();
	return (0);
}

std::auto_ptr<ClapTrap>	generate_new_trap(void)
{
	Name	name("Testy");

	std::auto_ptr<ClapTrap>	p = std::auto_ptr<ClapTrap>(new ClapTrap(name));
	return (std::auto_ptr<ClapTrap>(p.release()));
}
