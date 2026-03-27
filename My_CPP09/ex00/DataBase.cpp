/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:51:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 22:20:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataBase.hpp"
#include "DataFile.hpp"
#include <iostream>
#include <sstream>

namespace
{
	bool	validate_table_header(DataFile& data_file);
	std::pair<Date, double>	parse_row(const std::string& line);
	std::string	trim(const std::string& s);
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
			db_.insert(parse_row(line));
		}
		catch (...)
		{
			std::cerr << data_file.name() << ":";
			std::cerr << row_count << ": invalid line" << std::endl;
		}
	}
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
		try
		{
			Date date(date_str);
			return (date);
		}
		catch (std::invalid_argument& e)
		{
			throw std::runtime_error("invalid date format");
		}
	}

	double	parse_exchange_rate(std::stringstream& ss)
	{
		double		exchange_rate;
		std::string	exchange_rate_str;
		char		*endp;

		std::getline(ss, exchange_rate_str, ',');
		exchange_rate = std::strtod(exchange_rate_str.c_str(), &endp);
		if (exchange_rate_str == endp)
			throw ;
		return (exchange_rate);
	}

	bool	validate_table_header(DataFile& data_file)
	{
		std::string	head_line;
		data_file.get_line(head_line);
		return (trim(head_line) == "date,exchange_rate");
	}

	std::string	trim(const std::string& s)
	{
		size_t first = s.find_first_not_of(" \t\r\n");
		if (first == std::string::npos)
			return "";
		size_t last = s.find_last_not_of(" \t\r\n");
		return s.substr(first, (last - first + 1));
	}
}