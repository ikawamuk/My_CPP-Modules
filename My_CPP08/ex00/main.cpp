/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 22:09:34 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/22 01:43:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

namespace
{
	template <typename T>
	T	generate_odds_sequencial(void)
	{
		T	c;
	
		for (int n = 0; n < 10; ++n)
			c.push_back(n * 2 + 1);
		return (c);
	}

	template <typename T>
	void	sequencial_containnor_test(int value)
	{
		// const T	c = generate_odds_sequencial<T>();
		T	c = generate_odds_sequencial<T>();
	
		typename T::const_iterator i = easyfind<T>(c, value);
		if (i != c.end())
			std::cout << "found:" << *i << std::endl;
		else
			std::cout << "not found" << std::endl;
	}
}

int	main(int argc, char *argv[])
{
	const int	value = argc >= 2 ? std::atoi(argv[1]) : 0;

	sequencial_containnor_test<std::vector<int> >(value);
	sequencial_containnor_test<std::list<int> >(value);
	sequencial_containnor_test<std::deque<int> >(value);
	return (0);
}
