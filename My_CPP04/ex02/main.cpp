#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

namespace {
	void	delete_aanimals(AAnimal** aanimals_ptr, int size)
	{
		for (int i = 0; i < size; i++)
			delete aanimals_ptr[i];
		delete[] aanimals_ptr;
		return ;
	}
}

int main()
{
	int				N = 4;
	AAnimal**	aanimal_ptr_arr = new AAnimal*[N];
	int i;
	for (i = 0; i < N / 2; i++)
		aanimal_ptr_arr[i] = new Dog();
	aanimal_ptr_arr[i - 1]->getType();
	aanimal_ptr_arr[i - 1]->makeSound();
	for (i = N / 2; i < N; i++)
		aanimal_ptr_arr[i] = new Cat();
	aanimal_ptr_arr[i - 1]->getType();
	aanimal_ptr_arr[i - 1]->makeSound();
	delete_aanimals(aanimal_ptr_arr, N);
	return 0;
}
