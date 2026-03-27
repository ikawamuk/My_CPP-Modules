/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:05:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/28 00:12:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "input file name" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		BitcoinExchange	btc("data.csv");

		btc.execute(argv[1]);
		return (EXIT_SUCCESS);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
}
