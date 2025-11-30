#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

namespace
{
	void	materia_test(void)
	{
		std::cout << "---materia test---" << std::endl;
		AMateria*	ice = new Ice();
		AMateria*	cure = new Cure();
		AMateria*	ice_clone = ice->clone();
		AMateria*	cure_clone = cure->clone();
		ICharacter*	target = new Character("TARGET");

		std::cout << "ice type: " << ice->getType() << std::endl;
		std::cout << "cure type: " << cure->getType() << std::endl;
		std::cout << "ice clone type: " << ice_clone->getType() << std::endl;
		std::cout << "cure clone type: " << cure_clone->getType() << std::endl;
		ice_clone->use(*target);
		cure_clone->use(*target);

		delete ice;
		delete cure;
		delete ice_clone;
		delete cure_clone;
		delete target;
		return ;
	}

	void	character_test(void)
	{
		std::cout << "---character test---" << std::endl;
		ICharacter*	hero = new Character("HERO");
		ICharacter*	target = new Character("TARGET");
		AMateria*	ice1 = new Ice();
		AMateria*	ice2 = new Ice();
		AMateria*	cure1 = new Cure();
		AMateria*	cure2 = new Cure();

		std::cout << "Hero's name: " << hero->getName() << std::endl;

		hero->unequip(0);
		hero->unequip(3);
		hero->use(0, *target);
		hero->use(3, *target);

		hero->equip(ice1);
		hero->equip(ice2);
		hero->equip(cure1);
		hero->equip(cure2);

		hero->use(0, *target);
		hero->use(3, *target);
		
		hero->unequip(0);
		hero->use(0, *target);
		hero->unequip(1);
		hero->use(1, *target);
		hero->unequip(2);
		hero->use(2, *target);
		hero->unequip(3);
		hero->use(3, *target);

		for (int i = 0; i < 6; i++)
			hero->equip(new Ice());
		for (int i = 0; i < 6; i++)
			hero->use(i, *target);
		for (int i = 0; i < 6; i++)
			hero->unequip(i);

		delete hero;
		delete target;
	}

	void	materia_source_test(void)
	{
		std::cout << "---matera source test---" << std::endl;
		IMateriaSource*	source = new MateriaSource();
		ICharacter*		hero = new Character("HERO");
		ICharacter*		target = new Character("TARGET");

		hero->equip(source->createMateria("ice"));
		hero->use(0, *target);
		source->learnMateria(new Ice());
		source->learnMateria(new Cure());
		hero->equip(source->createMateria("ice"));
		hero->equip(source->createMateria("cure"));
		hero->use(0, *target);
		hero->use(1, *target);
		hero->use(2, *target);

		delete source;
		delete hero;
		delete target;
		return ;
	}

	void	default_test(void)
	{
		std::cout << "---default test---" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(0);
		delete bob;
		delete me;
		delete src;
		return ;
	}

	void	add_any_cases_you_want(void)
	{
		std::cout << "Add any cases you want." << std::endl;
		// here
		return ;
	}
}

int	main(void)
{
	materia_test();
	std::cout << std::endl;
	character_test();
	std::cout << std::endl;
	materia_source_test();
	std::cout << std::endl;
	default_test();
	std::cout << std::endl;
	std::cout << std::endl;
	add_any_cases_you_want();
	return (0);
}
