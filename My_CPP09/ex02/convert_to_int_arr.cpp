/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_int_arr.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:47:32 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/04/01 01:48:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <stdexcept>
#include <iostream>

int	*convert_to_int_arr(char **str_arr, int size)
{
	int *sequence = new int[size];
	
	for (int i = 0; i < size; ++i)
	{
		sequence[i] = std::atoi(str_arr[i]);
		if (sequence[i] < 0)
		{
			delete[] sequence;
			throw std::invalid_argument("negative number is not valid");
		}
	}
	return (sequence);
}
