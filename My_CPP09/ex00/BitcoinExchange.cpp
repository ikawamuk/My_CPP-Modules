/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:05:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/28 00:14:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& data_file_name)
{
	
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
	
}