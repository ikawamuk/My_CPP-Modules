/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:10:35 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 19:54:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static AForm	*new_ShrubberyCreationForm(const std::string& target);
static AForm	*new_RobotomyRequestForm(const std::string& target);
static AForm	*new_PresidentialPardonForm(const std::string& target);

static const FormTable	table[] = {
	{"shrubbery creation", new_ShrubberyCreationForm},
	{"robotomy request", new_RobotomyRequestForm},
	{"presidential pardon", new_PresidentialPardonForm}
};

AForm	*Intern::makeForm(const std::string& form_name, const std::string& target) const
{
	for (std::size_t i = 0; i < sizeof(table) / sizeof(table[0]); i++)
	{
		if (table[i].form_name == form_name)
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return table[i].new_form(target);
		}
	}
	std::cerr << "Error: Intern cannot create '" << form_name 
			<< "' because it doesn't exist." << std::endl;
	return (0);
}

static AForm	*new_ShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*new_RobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*new_PresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}
