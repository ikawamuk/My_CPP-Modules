/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:01:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/30 17:45:46 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>

#include <algorithm>
void	sort(std::vector<int>& vector)
{
	std::sort(vector.begin(), vector.end());
}

void	sort(std::list<int>& list)
{
	list.sort();
}

//
//#include <stdexcept>
//#include <iostream>
//template <typename Container>
//void test_sort(Container c)
//{
//	sort(c);
//	if (!std::is_sorted(c.begin(), c.end())) {
//		throw std::logic_error("sort function is incorrect");
//	}
//}

//void	test_sort_vector(int *sequence, int size)
//{
//	try
//	{
//		test_sort<std::vector<int> >(std::vector<int>(sequence, sequence + size));
//	}
//	catch(const std::exception&)
//	{
//		std::cerr << "void	sort(std::vector<int>&) is wrong" << std::endl;
//		return ;
//	}
//	std::cout << "vector OK" << std::endl;
//}

//void	test_sort_list(int *sequence, int size)
//{
//	try
//	{
//		test_sort<std::list<int> >(std::list<int>(sequence, sequence + size));
//	}
//	catch(const std::exception&)
//	{
//		std::cerr << "void	sort(std::list<int>&) is wrong" << std::endl;
//		return ;
//	}
//	std::cout << "list OK" << std::endl;
//}

//int	*convert_to_int_arr(char **str_arr, int size);
//int	main(int argc, char *argv[])
//{
//	int	size = argc - 1;
//	int	*sequence = convert_to_int_arr(argv + 1, size);
//	try
//	{
//		test_sort_vector(sequence, size);
//		test_sort_list(sequence, size);
//	}
//	catch(const std::exception& e)
//	{
//		std::cerr << e.what() << '\n';
//	}
//	delete[] sequence;
//	std::cout << "OK" << std::endl;
//}
//
