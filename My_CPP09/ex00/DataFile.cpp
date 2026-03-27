/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:49:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 20:21:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DataFile.hpp"

namespace
{
	bool	is_csv_extention(const std::string& file_name);
}

DataFile::DataFile(const std::string& csv_file_name)
:name_(csv_file_name), ifs_(csv_file_name)
{
	if (!is_csv_extention(name_))
		throw std::runtime_error("Only CSV files are allowed");
	if (!ifs_.is_open())
		throw std::runtime_error("Failed to open file");
}

DataFile::~DataFile()
{}

std::string		DataFile::name(void) const
{
	return (name_);
}

bool	DataFile::get_line(std::string& buf)
{
	std::getline(ifs_, buf);
	if (ifs_.eof())
		return (false);
	if (ifs_.fail())
		throw std::runtime_error("I/O error while reading file");
	return (true);
}

namespace
{
	bool	is_csv_extention(const std::string& file_name)
	{
		size_t pos = file_name.rfind('.');
		if (pos == std::string::npos || pos == 0)
			return false;
		return file_name.substr(pos + 1) == "csv";
	}
}
