/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:10:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 19:03:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "define.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
:AForm("Robotomy Request Form", ROBOTOMY_REQUEST_FORM_TO_SIGN, ROBOTOMY_REQUEST_FORM_TO_EXEC),
target_(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	throw_if_not_executable(executor);
	for (int i = 0; i < 3; i++)
	{
		std::cout << "\a\aVrrr-vrrr..." << std::endl;
		sleep(1);
	}
	if (std::rand() % 2 == 0)
		std::cout << this->target_ << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy on " << this->target_ << " failed." << std::endl;
}

const std::string&	RobotomyRequestForm::target(void) const
{
	return (target_);
}

RobotomyRequestForm::RobotomyRequestForm(void)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	(void)rhs;
	return (*this);
}
