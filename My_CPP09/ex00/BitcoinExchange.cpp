/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:05:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/28 06:14:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <iomanip>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <string>

namespace
{
	std::map<time_t, double>	build_data_base(std::ifstream& ifs);
	std::pair<std::time_t, double>	parse_csv_row(std::string row);
	std::time_t	parse_date(std::string date_str);
	std::string	convert_date_to_str(std::time_t date);
	double	parse_rate(std::string rate_str);
	std::string trim(std::string str);
	std::string	get_csv_item(std::istream& s);
	bool	is_valid_header(std::string header_line);
	double	parse_value(std::string value_str);
}

BitcoinExchange::BitcoinExchange(const std::string& data_file_name)
{
	std::ifstream	ifs(data_file_name.c_str());
	if (!ifs)
		throw std::invalid_argument("failed to open data file: " + data_file_name);
	std::string	header_line;
	std::getline(ifs, header_line);
	if (!is_valid_header(header_line))
		throw std::invalid_argument("invalid csv header: " + header_line);
	data_base_ = build_data_base(ifs);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
:data_base_(other.data_base_)
{}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
		data_base_ = rhs.data_base_;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::execute(const std::string& input_file_name) const
{
	std::ifstream	ifs(input_file_name.c_str());
	if (!ifs)
		throw std::invalid_argument("failed to open input file: " + input_file_name);
	std::string	line;
	std::getline(ifs, line);
	if (line != "date | value")
		throw std::invalid_argument("invalid headaer format: " + line);
	while (std::getline(ifs, line))
	{
		std::string sep = " | ";
		std::size_t pos = line.find(sep);
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date_str = line.substr(0, pos);
		std::string value_str = line.substr(pos + sep.length());
		try
		{
			std::time_t date = parse_date(date_str);
			double		value = parse_value(value_str);
			std::map<std::time_t, double>::const_iterator it = data_base_.upper_bound(date);
			if (it == data_base_.begin())
				throw std::runtime_error("no data available for this date or any earlier date.");
			--it;
			std::cout << convert_date_to_str(date) << " => " << it->second * value << std::endl;
		}
		catch (std::invalid_argument& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

namespace
{
	std::string trim(std::string str)
	{
		std::size_t first = str.find_first_not_of(" \t\r\n");
		if (first == std::string::npos)
			return "";
		std::size_t last = str.find_last_not_of(" \t\r\n");
		return str.substr(first, last - first + 1);
	}

	std::string	get_csv_item(std::istream& column)
	{
		std::string	item;
		std::getline(column, item, ',');
		return (item);
	}

	std::map<time_t, double>	build_data_base(std::ifstream& ifs)
	{
		std::map<time_t, double>	data_base;
		std::string	row;
		while (std::getline(ifs, row))
		{
			try
			{
				std::pair<const time_t, double> element = parse_csv_row(row);
				std::map<time_t, double>::iterator it = data_base.find(element.first);
				if (it == data_base.end())
					data_base.insert(element);
				else
					throw std::invalid_argument("dupulication of data");
			}
			catch (std::invalid_argument& e)
			{
				std::cout << "error:data file:" << e.what() << std::endl;
			}
		}
		return (data_base);
	}

	std::pair<std::time_t, double>	parse_csv_row(std::string row)
	{
		std::stringstream	ss(row);
		const std::time_t	date = parse_date(trim(get_csv_item(ss)));
		double				rate = parse_rate(trim(get_csv_item(ss)));
		if (!ss.eof())
			throw std::invalid_argument("invalid format.");
		return (std::pair<std::time_t, double>(date, rate));
	}

	std::time_t	parse_date(std::string date_str)
	{
		std::tm tm;
		std::memset(&tm, 0, sizeof(std::tm));
		char *res = strptime(date_str.c_str(), "%Y-%m-%d", &tm);
		if (!res || *res != '\0')
			throw std::invalid_argument("invalid format: " + date_str);
		std::time_t	date = std::mktime(&tm);
		if (convert_date_to_str(date) != date_str)
			throw std::invalid_argument("invalid date: " + date_str);
		return (date);
	}

	std::string	convert_date_to_str(std::time_t date)
	{
		char	buf[11];
		std::tm	*tm = std::localtime(&date);
		if (!tm)
			throw std::invalid_argument("failed to convert the date to string.");
		strftime(buf, sizeof(buf), "%Y-%m-%d", tm);
		return (buf);
	}

	double	parse_rate(std::string rate_str)
	{
		char	*endp;
		double rate = std::strtod(rate_str.c_str(), &endp);
		if (*endp != '\0' || rate < 0)
			throw std::invalid_argument("invalid exchange rate.");
		return (rate);
	}

	double	parse_value(std::string value_str)
	{
		char	*endp;
		double rate = std::strtod(value_str.c_str(), &endp);
		if (*endp != '\0')
			throw std::invalid_argument("invalid char included.");
		if (rate < 0)
			throw std::invalid_argument("not a positive number.");
		if (1000 < rate)
			throw std::invalid_argument("too large a number.");
		return (rate);
	}

	bool	is_valid_header(std::string header_line)
	{
		std::stringstream	ss(header_line);
		std::string	c1 = trim(get_csv_item(ss));
		std::string	c2 = trim(get_csv_item(ss));
		return (c1 == "date" && c2 == "exchange_rate");
	}
}
