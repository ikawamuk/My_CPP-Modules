/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:47:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 19:08:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "define.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
:AForm("Presidential Pardon Form", PRESIDENTIAL_PARDON_FORM_TO_SIGN, PRESIDENTIAL_PARDON_FORM_TO_EXEC),
target_(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	throw_if_not_executable(executor);
	std::cout << "Informs that " << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string&	PresidentialPardonForm::target(void) const
{
	return (target_);
}

PresidentialPardonForm::PresidentialPardonForm(void)
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	(void)rhs;
	return (*this);
}
