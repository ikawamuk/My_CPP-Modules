#include "ClapTrapFactory.hpp"

void	trap_test(Trap&);

int	main(void)
{
	ClapTrapFactory	fac;

	Trap*	p = fac.make("Testy");
	trap_test(*p);
	return (0);
}
