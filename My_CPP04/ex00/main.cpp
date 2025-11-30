#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	basic_test(void)
{
	std::cout << "---basic test---" << std::endl;
	{
		Animal	animal;
		std::cout << animal.getType() << std::endl;
		animal.makeSound();
	}
	std::cout << std::endl;
	{
		Dog	dog;
		std::cout << dog.getType() << std::endl;
		dog.makeSound();
	}
	std::cout << std::endl;
	{
		Cat	cat;
		std::cout << cat.getType() << std::endl;
		cat.makeSound();
	}
	std::cout << std::endl;
	return ;
}

void	copy_test(void)
{
	std::cout << "---copy test---" << std::endl;
	{
		Dog		dog;
		Animal	copy(dog);
		Animal	asign;
		asign = dog;

		std::cout << dog.getType() << std::endl;
		dog.makeSound();
		std::cout << copy.getType() << std::endl;
		copy.makeSound();
		std::cout << asign.getType() << std::endl;
		asign.makeSound();
	}
	std::cout << std::endl;
	{
		Cat		cat;
		Animal	copy(cat);
		Animal	asign;
		asign = cat;

		std::cout << cat.getType() << std::endl;
		cat.makeSound();
		std::cout << copy.getType() << std::endl;
		copy.makeSound();
		std::cout << asign.getType() << std::endl;
		asign.makeSound();
	}
	// {
		// Animal	a;
		// Cat		c;

		// c = a;
	// }
	std::cout << std::endl;
}

void	reference_test(void)
{
	std::cout << "---reference test---" << std::endl;
	{
		Dog		dog;
		Animal&	ref(dog);

		std::cout << dog.getType() << std::endl;
		dog.makeSound();
		std::cout << ref.getType() << std::endl;
		ref.makeSound();
	}
	std::cout << std::endl;
	{
		Cat		cat;
		Animal&	ref(cat);

		std::cout << cat.getType() << std::endl;
		cat.makeSound();
		std::cout << ref.getType() << std::endl;
		ref.makeSound();
	}
	std::cout << std::endl;
	// {
		// Animal	a;
		// Cat&	c = a;
	// }
}

void	pointer_test(void)
{
	std::cout << "---ptr test(given test)---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
}

void	wrong_animal_test(void)
{
	std::cout << "---wrong animdl test---" << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the animal sound!
	meta->makeSound();
	delete meta;
	delete i;
	std::cout << std::endl;
}

int main()
{
	basic_test();
	copy_test();
	reference_test();
	pointer_test();
	wrong_animal_test();
	return (0);
}
