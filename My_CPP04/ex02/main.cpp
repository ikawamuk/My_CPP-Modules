#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void	default_test(void)
{
	std::cout << "---default test---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;
	return ;
}

Animal**	generate_animals(int size)
{
	Animal**	animals = new Animal*[size];

	for (int i = 0; i < size; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	return (animals);
}

void	delete_animals(int size, Animal** animals)
{
	for (int i = 0; i < size; i++)
		delete animals[i];
	delete[] animals;
	return ;
}

void	delete_animal_arr_test(void)
{
	std::cout << "---delete animal arr test---" << std::endl;
	int			size = 5;
	Animal**	animals = generate_animals(size);
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();
	delete_animals(size, animals);
	return ;
}

void	deep_copy_test1(void)
{
	std::cout << "---brain set test1---" << std::endl;
	Dog	src_dog;
	Dog	dst_dog;

	src_dog.think("I'm hungry");
	dst_dog = src_dog;
	std::cout << "src dog: ";
	src_dog.makeSound();
	std::cout << "dst dog: ";
	dst_dog.makeSound();
	src_dog.think("I feel like having some delicious sauce!");
	dst_dog.think("Me too! It's a distiny!");
	std::cout << "src dog: ";
	src_dog.makeSound();
	std::cout << "dst dog: ";
	dst_dog.makeSound();
	return ;
}

void	deep_copy_test2(void)
{
	std::cout << "---brain set test2---" << std::endl;
	Cat	src_cat;
	src_cat.think("I'm hungry");
	Cat	dst_cat(src_cat);

	std::cout << "src cat: ";
	src_cat.makeSound();
	std::cout << "dst cat: ";
	dst_cat.makeSound();
	src_cat.think("I feel like having some delicious sauce!");
	dst_cat.think("Me too! It's a distiny!");
	std::cout << "src cat: ";
	src_cat.makeSound();
	std::cout << "dst cat: ";
	dst_cat.makeSound();
	return ;
}

int main(void)
{
	default_test();
	std::cout << std::endl;
	delete_animal_arr_test();
	std::cout << std::endl;
	deep_copy_test1();
	std::cout << std::endl;
	deep_copy_test2();
	std::cout << std::endl;
	return 0;
}