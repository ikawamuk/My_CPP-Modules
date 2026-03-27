/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:13:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 23:36:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "DataBase.hpp"
#include "DataFile.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange(DataFile& data_file)
:data_base_(data_file)
{}

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
	std::string		line;

	while (std::getline(ifs, line))
	{
		try
		{
			Date date(line);
			double rate = get_rate(date);
			if (rate != rate)
				throw std::invalid_argument("unregistered date");
			std::cout << date << " => ";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

DataBase	BitcoinExchange::data_base(void) const
{
	return (data_base_);
}

double	BitcoinExchange::get_rate(const Date& date) const
{
	return (data_base_.find(date));
}
