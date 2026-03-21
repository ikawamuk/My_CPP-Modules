/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:03:01 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/22 01:39:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>

namespace
{
	void		test_intern(void);
	void	use_intern(const std::string &form_name, const std::string &target);
}

int	main(void)
{
	test_intern();
	std::cout << "\nEnd." << std::endl;
}

namespace
{
	void	test_intern(void)
	{
		use_intern("shrubbery creation", "Bob");
		use_intern("robotomy request", "Bob");
		use_intern("presidential pardon", "Bob");
	}
	
	void	use_intern(const std::string &form_name, const std::string &target)
	{
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm(form_name, target);
		Bureaucrat	br("Bob", 1);
		br.signForm(*rrf);
		br.executeForm(*rrf);
		delete rrf;
	}
}
