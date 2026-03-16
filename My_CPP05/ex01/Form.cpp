/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:37:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 18:23:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "define.h"
#include <sstream>

const int Form::top_grade = TOP_GRADE;
const int Form::bottom_grade = BOTTOM_GRADE;

Form::GradeTooHighException::GradeTooHighException(const std::string& msg)
:std::runtime_error(msg)
{}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg)
:std::runtime_error(msg)
{}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute)
:name_(name), is_signed_(false), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute)
{
	throw_if_higher_than_top_grade(grade_to_sign_);
	throw_if_lower_than_top_grade(grade_to_sign_);
	throw_if_higher_than_top_grade(grade_to_execute);
	throw_if_lower_than_top_grade(grade_to_execute);
}

void	Form::throw_if_higher_than_top_grade(int grade)
{
	if (grade < top_grade)
	{
		std::stringstream ss;
		ss << "Grade is Too High. top grade is" << top_grade;
		throw Form::GradeTooHighException(ss.str());
	}
}

void	Form::throw_if_lower_than_top_grade(int grade)
{
	if (grade > bottom_grade)
	{
		std::stringstream ss;
		ss << "Grade is Too Low. top grade is" << bottom_grade;
		throw Form::GradeTooLowException(ss.str());
	}
}

Form::~Form()
{}

void	Form::beSign(const Bureaucrat& b)
{
	if (b.getGrade() > grade_to_sign_)
	{
		std::stringstream ss;
		ss << "Bureaucrat's grade is too low to sign. required " << grade_to_sign_;
		throw Form::GradeTooLowException(ss.str());
	}
	is_signed_ = true;
}

// Gettter

const std::string&	Form::name(void) const
{
	return (name_);
}

bool	Form::is_signed(void) const
{
	return (is_signed_);
}

int	Form::grade_to_sign(void) const
{
	return (grade_to_sign_);
}

int	Form::grade_to_execute(void) const
{
	return (grade_to_execute_);
}

// operator function

std::ostream&	operator<<(std::ostream& os, const Form& fo)
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

Form::Form(void)
:name_(), is_signed_(false), grade_to_sign_(), grade_to_execute_()
{}

Form&	Form::operator=(const Form& rhs)
{
	(void)rhs;
	return (*this);
}
