/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:03:01 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/04/01 23:24:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

namespace
{
	void	form_test(void);
	void	form_construct_test(const std::string& name, int sign_grade, int exe_grade);
	void	sign_test(void);
}

int	main(void)
{
	form_test();
	std::cout << "----" << std::endl;
	sign_test();
	std::cout << "\nEnd." << std::endl;
}

namespace
{
	void	form_test(void)
	{
		form_construct_test("TaxReturn", 1, 150);
		form_construct_test("TaxReturn", 0, 150);
		form_construct_test("TaxReturn", 1, 151);
	}
	
	void	sign_test(void)
	{
		Bureaucrat	br1("Bob1", 101);
		Bureaucrat	br2("Bob2", 102);
		Form		fo("TaxReturn", 100, 101);
	
		std::cout << br1 << std::endl;
		br1.signForm(fo);
		br1.promote();
		br1.signForm(fo);
		std::cout << "----" << std::endl;
		std::cout << br2 << std::endl;
		br2.signForm(fo);
		br2.promote();
		br2.signForm(fo);
	}
	
	void	form_construct_test(const std::string& name, int sign_grade, int exe_grade)
	{
		try
		{
			Form	br(name, sign_grade, exe_grade);
			std::cout << br << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception Caught!\n";
		}
	}
}
