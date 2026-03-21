/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:42:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/22 01:55:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
# include <iostream>

template <typename T>
void	print_T_address(const T& val)
{
	std::cout << "argument's adddress: " << &val << std::endl;
}

int	main(void)
{
	static const int	ARR_SIZE = 3;
	{
		int	int_arr[ARR_SIZE] = {1, 3, 5};
		iter<int>(int_arr, ARR_SIZE, print_T_address<int>);
	}
	{
		const std::string	str_arr[ARR_SIZE] = {"AB", "CD", "EF"};
		iter<const std::string>(str_arr, ARR_SIZE, print_T_address<const std::string>);
	}
}
