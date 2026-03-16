/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:37:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 19:50:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "define.h"
#include <sstream>

const int AForm::top_grade = TOP_GRADE;
const int AForm::bottom_grade = BOTTOM_GRADE;

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg)
:std::runtime_error(msg)
{}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg)
:std::runtime_error(msg)
{}

AForm::FormNotSignedException::FormNotSignedException(const std::string& msg)
:std::runtime_error(msg)
{}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute)
:name_(name), is_signed_(false), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute)
{
	throw_if_higher_than_top_grade(grade_to_sign_);
	throw_if_lower_than_top_grade(grade_to_sign_);
	throw_if_higher_than_top_grade(grade_to_execute);
	throw_if_lower_than_top_grade(grade_to_execute);
}

void	AForm::throw_if_higher_than_top_grade(int grade)
{
	if (grade < top_grade)
	{
		std::stringstream ss;
		ss << "Grade is Too High. top grade is" << top_grade;
		throw AForm::GradeTooHighException(ss.str());
	}
}

void	AForm::throw_if_lower_than_top_grade(int grade)
{
	if (grade > bottom_grade)
	{
		std::stringstream ss;
		ss << "Grade is Too Low. top grade is" << bottom_grade;
		throw AForm::GradeTooLowException(ss.str());
	}
}

AForm::~AForm()
{}

void	AForm::beSign(const Bureaucrat& b)
{
	if (b.getGrade() > grade_to_sign_)
	{
		std::stringstream ss;
		ss << "Bureaucrat's grade is too low to sign. required " << grade_to_sign_;
		throw AForm::GradeTooLowException(ss.str());
	}
	is_signed_ = true;
}

// Gettter

const std::string&	AForm::name(void) const
{
	return (name_);
}

bool	AForm::is_signed(void) const
{
	return (is_signed_);
}

int	AForm::grade_to_sign(void) const
{
	return (grade_to_sign_);
}

int	AForm::grade_to_execute(void) const
{
	return (grade_to_execute_);
}

// protected method

void	AForm::throw_if_not_executable(Bureaucrat const & b) const
{
	if (!is_signed_)
		throw FormNotSignedException("cannot execute an unsigned form");
	if (b.getGrade() > grade_to_execute_)
	{
		std::stringstream ss;
		ss << "Bureaucrat's grade is too low to execute. required " << grade_to_execute_;
		throw AForm::GradeTooLowException(ss.str());
	}
}

// operator function

std::ostream&	operator<<(std::ostream& os, const AForm& fo)
{
	os << std::boolalpha;
	os << "Name:" << fo.name() << " ";
	os << "is_signed:" <<  fo.is_signed() << " ";
	os << "grade_to_sign:" << fo.grade_to_sign() << " ";
	os << "grade_to_execute:" << fo.grade_to_execute();
	os << std::noboolalpha;
	return (os);
}

// private method

AForm::AForm(void)
:name_(), is_signed_(false), grade_to_sign_(), grade_to_execute_()
{}

AForm&	AForm::operator=(const AForm& rhs)
{
	(void)rhs;
	return (*this);
}
