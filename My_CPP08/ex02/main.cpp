/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:23:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/25 21:24:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>
#include <iostream>

void	in_order_test(void);
void	rev_order_test(void);

int	main(void)
{
	in_order_test();
	rev_order_test();
	return (0);
}

void	rev_order_test(void)
{
	MutantStack<std::string>	mstack;

	for (int i = 0; i < 2; ++i)
	{
		std::cout << "Title: ";
		std::string	title;
		if (!std::getline(std::cin, title)) break ;
		mstack.push(title);
	}
	for (MutantStack<std::string>::reverse_iterator i = mstack.rbegin(); i != mstack.rend(); ++i)
	{
		std::cout << *i << std::endl;
		mstack.pop();
	}
}

void	in_order_test(void)
{
	MutantStack<std::string>	mstack;

	for (int i = 0; i < 2; ++i)
	{
		std::cout << "Title: ";
		std::string	title;
		if (!std::getline(std::cin, title)) break ;
		mstack.push(title);
	}
	for (MutantStack<std::string>::iterator i = mstack.begin(); i != mstack.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	for (MutantStack<std::string>::iterator i = mstack.begin(); !mstack.empty(); ++i)
	{
		mstack.pop();
	}
}
