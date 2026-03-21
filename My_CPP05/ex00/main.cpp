/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:03:01 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/22 01:33:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

namespace
{
	void	construct_test(const std::string& name, int grade);
	void	promot_test(Bureaucrat br);
	void	demot_test(Bureaucrat br);
}

int	main(void)
{
	construct_test("Bob", 1);
	construct_test("Bob", 0);
	construct_test("Bob", 150);
	construct_test("Bob", 151);
	std::cout << "-----" << std::endl;
	promot_test(Bureaucrat("Bob", 1));
	promot_test(Bureaucrat("Bob", 2));
	promot_test(Bureaucrat("Bob", 150));
	promot_test(Bureaucrat("Bob", 149));
	std::cout << "-----" << std::endl;
	demot_test(Bureaucrat("Bob", 1));
	demot_test(Bureaucrat("Bob", 2));
	demot_test(Bureaucrat("Bob", 150));
	demot_test(Bureaucrat("Bob", 149));
	
	std::cout << "\nEnd." << std::endl;
}

namespace
{
	void	promot_test(Bureaucrat br)
	{
		try
		{
			std::cout << "Before: " << br << std::endl;
			br.promote();
			std::cout << "After: " << br << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception Caught!\n";
		}
		std::cout << std::endl;
	}
	
	void	demot_test(Bureaucrat br)
	{
		try
		{
			std::cout << "Before: " << br << std::endl;
			br.demote();
			std::cout << "After: " << br << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception Caught!\n";
		}
		std::cout << std::endl;
	}
	
	void	construct_test(const std::string& name, int grade)
	{
			try
			{
				Bureaucrat	br(name, grade);
				std::cout << br << std::endl;
			}
			catch (std::exception& e)
			{
				std::cout << "Exception Caught!\n";
			}
		}
}
