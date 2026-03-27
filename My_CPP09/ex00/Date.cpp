/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:07:17 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 22:33:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(void)
{}

Date::Date(const std::string& date_str)
{
	
}

Date::Date(const Date& other)
:year_(other.year_), month_(other.month_), day_(other.day_)
{}

Date&	Date::operator=(const Date& rhs)
{
	if (this != &rhs)
	{
		year_ = rhs.year_;
		month_ = rhs.month_;
		day_ = rhs.day_;
	}
	return (*this);
}

Date::~Date()
{}

unsigned int	Date::year(void) const
{
	return (year_);
}

unsigned int	Date::month(void) const
{
	return (month_);
}

unsigned int	Date::day(void) const
{
	return (day_);
}


std::ostream&	operator<<(std::ostream& os, const Date& date)
{
	os << date.year() << "-" << date.month() << "-" << date.day();
	return (os);
}
