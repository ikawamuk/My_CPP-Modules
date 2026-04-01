#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

int		 test(int, char**);
void	copy_constructor_assignment_test(void);
void	out_of_range_test(void);
void	cleanup_test(void);

int	main(int ac, char* av[])
{
	test(ac, av);
	return (0);
}

int test(int, char**)
{
	copy_constructor_assignment_test();
	out_of_range_test();
	cleanup_test();
	return 0;
}

void	copy_constructor_assignment_test(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	Array<int> tmp = numbers;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (tmp[i] != numbers[i])
		{
			std::cerr << "copy mismatch: tmp" << std::endl;
			delete[] mirror;
			return ;
		}
	}
	Array<int> test(tmp);
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (test[i] != numbers[i])
		{
			std::cerr << "copy mismatch: test" << std::endl;
			delete[] mirror;
			return ;
		}
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return ;
		}
	}
	delete[] mirror;
	std::cout << "copy_constructor_assignment_test: SUCCESS" << std::endl;
}

void	out_of_range_test(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error message is" << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error message is" << e.what() << '\n';
	}
	delete[] mirror;
	std::cout << "out_of_range_test: SUCCESS(if errore messages are shown currectly)" << std::endl;
}

void	cleanup_test(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror;
	std::cout << "cleanup_test: SUCCESS" << std::endl;
}
