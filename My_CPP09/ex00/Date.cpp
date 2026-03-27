/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:07:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 23:40:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <stdexcept>

Date::Date(void)
:time_()
{}

Date::Date(const std::string& date_str)
{
	std::tm	t;
	int	year, month, day;
	if (date_str.length() != 10
	|| std::sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		throw std::invalid_argument("Invalid date format: " + date_str);
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	std::time_t result = std::mktime(&t);
	if (result == (std::time_t)-1)
		throw std::invalid_argument("Time conversion failed: " + date_str);
	if (t.tm_year != year - 1900 || t.tm_mon != month - 1 || t.tm_mday != day)
		throw std::invalid_argument("Non-existent date: " + date_str);
	time_ = result;
}

Date::Date(const Date& other)
:time_(other.time_)
{}

Date&	Date::operator=(const Date& rhs)
{
	if (this != &rhs)
		time_ = rhs.time_;
	return (*this);
}

Date::~Date()
{}

time_t	Date::time(void) const
{
	return (time_);
}

std::string	Date::to_str(void) const
{
	std::tm* lt = std::localtime(&time_);
	std::stringstream	ss;

	ss << std::setw(4) << std::setfill('0') << (lt->tm_year + 1900)
	<< "-" << std::setw(2) << std::setfill('0') << (lt->tm_mon + 1)
	<< "-" << std::setw(2) << std::setfill('0') << lt->tm_mday;
	return (ss.str());
}

std::ostream&	operator<<(std::ostream& os, const Date& date)
{
	os << date.to_str();
	return (os);
}

bool	operator<(const Date& lhs, const Date& rhs)
{
	return (lhs.time() < rhs.time());
}

bool	operator>(const Date& lhs, const Date& rhs)
{
	return (rhs < lhs);
}

bool	operator>=(const Date& lhs, const Date& rhs)
{
	return (!(lhs < rhs));
}

bool	operator<=(const Date& lhs, const Date& rhs)
{
	return (!(lhs > rhs));
}
