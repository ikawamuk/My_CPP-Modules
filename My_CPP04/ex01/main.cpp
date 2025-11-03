#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

namespace {
	void	delete_animals(Animal** animals_ptr, int size)
	{
		for (int i = 0; i < size; i++)
			delete animals_ptr[i];
		delete[] animals_ptr;
		return ;
	}
}

int main()
{
	int				N = 4;
	Animal**	animal_ptr_arr = new Animal*[N];
	int i;
	for (i = 0; i < N / 2; i++)
		animal_ptr_arr[i] = new Dog();
	animal_ptr_arr[i - 1]->getType();
	animal_ptr_arr[i - 1]->makeSound();
	for (i = N / 2; i < N; i++)
		animal_ptr_arr[i] = new Cat();
	animal_ptr_arr[i - 1]->getType();
	animal_ptr_arr[i - 1]->makeSound();
	delete_animals(animal_ptr_arr, N);
	return 0;
}
