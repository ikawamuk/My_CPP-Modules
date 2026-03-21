/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:10:18 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/21 22:20:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>

static void	given_case(void);
static void test_10000(void);

static void	test_add_number(void)
{
	Span	span(2);

	std::cout << "--- test addNumber() ---" << std::endl;
	std::cout << "N: " << span.N() << std::endl;
	try
	{
		std::cout << "store[0]: " << span.store().at(0) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	span.addNumber(111);
	span.addNumber(112);
	std::cout << "store[0]: " << span.store().at(0) << std::endl;
	std::cout << "store[1]: " << span.store().at(1) << std::endl;
}

static void	test_spans(void)
{
	std::cout << "--- test shortestSpan() and longestSpan() ---" << std::endl;
	given_case();
	test_10000();
}

void test_10000(void)
{
	std::vector<int> v;
	Span sp(10002);

	for (int i = 0; i < 10000; ++i)
		v.push_back((std::rand() % 50000) + 1); // 1..50000
	v.push_back(0);
	v.push_back(50001);
	sp.addNumber(v.begin(), v.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void	given_case(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return ;
}

int	main(void)
{
	test_add_number();
	test_spans();
	return (0);
}
