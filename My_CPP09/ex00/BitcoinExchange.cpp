/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:13:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 20:25:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
# include "DataBase.hpp"
# include "DataFile.hpp"

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
