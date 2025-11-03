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

	void	animal_arr_test(int N = 3)
	{
		if (N < 3)
			N = 3;
		Animal**	animal_ptr_arr = new Animal*[N];
		for (int i = 0; i < N; i++)
		{
			switch (i % 3)
			{
			case (0):
				animal_ptr_arr[i] = new Animal();
				break;
			case (1):
				animal_ptr_arr[i] = new Dog();
				break;
			case (2):
				animal_ptr_arr[i] = new Cat();
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			std::cout << animal_ptr_arr[i]->getType() << ": ";
			animal_ptr_arr[i]->makeSound();
		}
		delete_animals(animal_ptr_arr, 3);
	}

	void	brain_test(void)
	{
		Brain	hoge;
		Dog		dog;
		Cat		cat;

		std::cout << dog.brain().ideas()[0] << std::endl;
		std::cout << cat.brain().ideas()[0] << std::endl;

		dog.brain().set_an_idea("I am the gratest dog", 0);
		cat.brain().set_an_idea("I am the gratest cat", 0);
		std::cout << dog.brain().ideas()[0] << std::endl;
		std::cout << cat.brain().ideas()[0] << std::endl;
		cat.brain() = dog.brain();
		std::cout << dog.brain().ideas()[0] << std::endl;
		std::cout << cat.brain().ideas()[0] << std::endl;
	}
}

int main()
{
	animal_arr_test();
	brain_test();
	return (0);
}
