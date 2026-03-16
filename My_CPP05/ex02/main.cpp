/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:03:01 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 19:11:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

static void	case_execute_form_success(AForm &f);
static void	case_execute_form_fail_unsigned(AForm &f);
static void	case_execute_form_fail_signed(AForm &f);
void		test_ShrubberyCreationForm(void);
void		test_RobotomyRequestForm(void);
void		test_PresidentialPardonForm(void);

int	main(void)
{
	test_ShrubberyCreationForm();
	std::cout << "\n--------------------\n" << std::endl;
	test_RobotomyRequestForm();
	std::cout << "\n--------------------\n" << std::endl;
	test_PresidentialPardonForm();
	std::cout << "\nEnd." << std::endl;
}

void	test_ShrubberyCreationForm(void)
{
	{
		ShrubberyCreationForm	ppf = ShrubberyCreationForm("target1");
		case_execute_form_success(ppf);
	}
	std::cout << "----" << std::endl;
	{
		ShrubberyCreationForm	ppf = ShrubberyCreationForm("target2");
		case_execute_form_fail_unsigned(ppf);
	}
	std::cout << "----" << std::endl;
	{
		ShrubberyCreationForm	ppf = ShrubberyCreationForm("target3");
		case_execute_form_fail_signed(ppf);
	}
}

void	test_RobotomyRequestForm(void)
{
	{
		RobotomyRequestForm	ppf = RobotomyRequestForm("target");
		case_execute_form_success(ppf);
	}
	std::cout << "----" << std::endl;
	{
		RobotomyRequestForm	ppf = RobotomyRequestForm("target");
		case_execute_form_fail_unsigned(ppf);
	}
	std::cout << "----" << std::endl;
	{
		RobotomyRequestForm	ppf = RobotomyRequestForm("target");
		case_execute_form_fail_signed(ppf);
	}
}

void	test_PresidentialPardonForm(void)
{
	{
		PresidentialPardonForm	ppf = PresidentialPardonForm("target");
		case_execute_form_success(ppf);
	}
	std::cout << "----" << std::endl;
	{
		PresidentialPardonForm	ppf = PresidentialPardonForm("target");
		case_execute_form_fail_unsigned(ppf);
	}
	std::cout << "----" << std::endl;
	{
		PresidentialPardonForm	ppf = PresidentialPardonForm("target");
		case_execute_form_fail_signed(ppf);
	}
}

static void	case_execute_form_success(AForm &f)
{
	Bureaucrat	br("Bob", 1);

	br.signForm(f);
	br.executeForm(f);
}

static void	case_execute_form_fail_unsigned(AForm &f)
{
	Bureaucrat	br1("Bob", 1);
	Bureaucrat	br2("Bob", 150);

	br1.signForm(f);
	br2.executeForm(f);
}

static void	case_execute_form_fail_signed(AForm &f)
{
	Bureaucrat	br1("Bob", 1);
	Bureaucrat	br2("Bob", 150);

	br2.signForm(f);
	br1.executeForm(f);
}
