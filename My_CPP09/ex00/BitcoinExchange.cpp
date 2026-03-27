/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:13:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 06:20:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

namespace
{
	std::map<Date, double>	to_db(const std::ifstream& file);
}

BitcoinExchange::BitcoinExchange(const std::string& db_file_name)
{
	std::ifstream	file(db_file_name);

	data_base_ = to_db(file);
}

namespace
{
	std::map<Date, double>	to_db(const std::ifstream& file)
	{
		std::map<Date, double>	db;

		return (db);
	}
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
