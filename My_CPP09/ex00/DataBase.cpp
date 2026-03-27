/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:51:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 23:36:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"
#include "DataFile.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>

std::string	trim(const std::string& s);

namespace
{
	bool	validate_table_header(DataFile& data_file);
	std::pair<Date, double>	parse_row(const std::string& line);
	Date	parse_date(std::stringstream& ss);
	double	parse_exchange_rate(std::stringstream& ss);
}

DataBase::DataBase(DataFile& data_file)
{
	if (!validate_table_header(data_file))
		throw std::runtime_error("invalid csv header");
	std::string	line;
	std::size_t	row_count = 1;
	while (data_file.get_line(line))
	{
		++row_count;
		if (trim(line).empty())
			continue ;
		try
		{
			rates_by_date_.insert(parse_row(line));
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << data_file.name() << ":";
			std::cerr << row_count << ": " << e.what() << std::endl;
		}
	}
}

DataBase::DataBase(const DataBase& other)
:rates_by_date_(other.rates_by_date_)
{}

DataBase&	DataBase::operator=(const DataBase& rhs)
{
	if (this != &rhs)
		rates_by_date_ = rhs.rates_by_date_;
	return (*this);
}

DataBase::~DataBase()
{}

std::map<Date, double>	DataBase::rates_by_date() const
{
	return (rates_by_date_);
}

double	DataBase::find(const Date& date) const
{
	std::map<Date, double>::const_iterator	it = rates_by_date_.find(date);
	if (it != rates_by_date_.end())
		return (it->second);
	return (std::numeric_limits<double>::quiet_NaN());
}

namespace
{
	std::pair<Date, double>	parse_row(const std::string& row)
	{
		std::stringstream	ss(row);
		Date	date = parse_date(ss);
		double	exchange_rate = parse_exchange_rate(ss);
		return (std::make_pair(date, exchange_rate));
	}

	Date	parse_date(std::stringstream& ss)
	{
		std::string	date_str;

		std::getline(ss, date_str, ',');
		return (Date(date_str));
	}

	double	parse_exchange_rate(std::stringstream& ss)
	{
		double		exchange_rate;
		std::string	exchange_rate_str;
		char		*endp;

		std::getline(ss, exchange_rate_str, ',');
		exchange_rate = std::strtod(exchange_rate_str.c_str(), &endp);
		if (*endp)
			throw std::invalid_argument("invalid exchange_rate format");
		return (exchange_rate);
	}

	bool	validate_table_header(DataFile& data_file)
	{
		std::string	head_line;
		data_file.get_line(head_line);
		return (trim(head_line) == "date,exchange_rate");
	}
}
