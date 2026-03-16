/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:36:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 19:03:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "define.h"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:AForm("Shrubbery Creation Form", ROBOTOMY_REQUEST_FORM_TO_SIGN, ROBOTOMY_REQUEST_FORM_TO_EXEC),
target_(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	throw_if_not_executable(executor);
	std::string filename = target_ + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: ファイルを作成できませんでした。" << std::endl;
		return;
	}
	outfile << "      ###" << std::endl;
	outfile << "     #o###" << std::endl;
	outfile << "   #####o###" << std::endl;
	outfile << "  #o#\\#|#/###" << std::endl;
	outfile << "   ###\\|/##o#" << std::endl;
	outfile << "    # }|{  #" << std::endl;
	outfile << "      }|{" << std::endl;
	outfile.close();
	std::cout << "Shrubbery has created successfully!" << std::endl;
}

const std::string&	ShrubberyCreationForm::target(void) const
{
	return (target_);
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	(void)rhs;
	return (*this);
}
