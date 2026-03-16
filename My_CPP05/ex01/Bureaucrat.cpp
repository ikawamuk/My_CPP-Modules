/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 00:36:30 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 15:14:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "define.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

int Bureaucrat::top_grade = TOP_GRADE;
int Bureaucrat::bottom_grade = BOTTOM_GRADE;

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg)
:std::runtime_error(msg)
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg)
:std::runtime_error(msg)
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
:name_(name), grade_(grade)
{
	if (grade_ < top_grade)
		throw_too_high_grade();
	if (grade_ > bottom_grade)
		throw_too_low_grade();
}

void	Bureaucrat::throw_too_high_grade(void)
{
	std::stringstream ss;
	ss << "Grade is Too High. top grade is" << top_grade;
	throw Bureaucrat::GradeTooHighException(ss.str());
}

void	Bureaucrat::throw_too_low_grade(void)
{
	std::stringstream ss;
	ss << "Grade is Too Low. top grade is" << bottom_grade;
	throw Bureaucrat::GradeTooLowException(ss.str());
}

Bureaucrat::~Bureaucrat()
{}

void	Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSign(*this);
		std::cout << getName() << " signed " << f.name() << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cerr << getName() << " couldn't sign " << f.name()
		<< " because " << e.what() << std::endl;
	}
}

// Gettter

const std::string&	Bureaucrat::getName(void) const
{
	return (name_);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade_);
}

// Promote / Demote

void	Bureaucrat::promote(void)
{
	if (grade_ <= top_grade)
		throw_too_high_grade();
	grade_--;
	std::cout << name_ << " has promoted. Grade is " << grade_ << std::endl;
}

void	Bureaucrat::demote(void)
{
	if (grade_ >= bottom_grade)
		throw_too_low_grade();
	grade_++;
	std::cout << name_ << " has demoted. Grade is " << grade_ << std::endl;
}

// operator function

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& br)
{
	os << br.getName() << ", " << "bureaucrat grade " << br.getGrade() << ".";
	return (os);
}

// private method

Bureaucrat::Bureaucrat(void)
:name_("unknown"), grade_()
{}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	(void)rhs;
	return (*this);
}

