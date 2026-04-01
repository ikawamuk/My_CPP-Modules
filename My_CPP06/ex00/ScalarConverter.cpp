/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 20:41:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/04/02 05:25:25 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cctype>

namespace
{
	bool	is_nan(double d);
	bool	is_inf(double d);
	void	error_case(void);
	void	convert_to_char(double value);
	void	convert_to_int(double value);
	void	convert_to_float(double value);
	void	convert_to_double(double value);
	double	special_float_strtod(const std::string& str);
}

void	ScalarConverter::convert(const std::string& str)
{
	const char	*str_head = str.c_str();
	char		*endp;
	double	value = std::strtod(str_head, &endp);
	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf")
		value = special_float_strtod(str);
	else if (str_head == endp || *endp != '\0')
	{
		error_case();
		return ;
	}
	convert_to_char(value);
	convert_to_int(value);
	convert_to_float(value);
	convert_to_double(value);
}

namespace
{
	double	special_float_strtod(const std::string& str)
	{
		double value = +0;

		if (str == "inff" || str == "+inff")
			value = std::numeric_limits<double>::infinity();
		else if (str  == "-inff")
			value = -std::numeric_limits<double>::infinity();
		else if (str == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		return (value);
	}

	void	error_case(void)
	{
		std::cout << "char: impossible" <<std::endl;
		std::cout << "int: impossible" <<std::endl;
		std::cout << "float: impossible" <<std::endl;
		std::cout << "double: impossible" <<std::endl;
	}

	void	convert_to_char(double value)
	{
		std::cout << "char: ";
		if (is_nan(value) || is_inf(value))
		{
			std::cout << "impossible" << std::endl;
			return ;
		}
		char	c = static_cast<char>(value);
		if (std::isprint(static_cast<int>(c)))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	void	convert_to_int(double value)
	{
		std::cout << "int: ";
		if (is_nan(value) || is_inf(value))
		{
			std::cout << "impossible" << std::endl;
			return ;
		}
		std::cout << static_cast<int>(value) << std::endl;
	}
	
	void	convert_to_float(double value)
	{
		static const int SIG_FIGS = 7;
		std::streamsize default_p = std::cout.precision();
		std::cout << std::setprecision(SIG_FIGS);
		std::cout << "float: ";
		if (is_inf(value) && value > 0)
			std::cout << "+";
		std::cout << static_cast<float>(value);
		if (static_cast<float>(value) == static_cast<long>(value))
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << std::setprecision(default_p);
	}
	
	void	convert_to_double(double value)
	{
		static const int SIG_FIGS = 15;
		std::streamsize default_p = std::cout.precision();
		std::cout << std::setprecision(SIG_FIGS);
		std::cout << "double: ";
		if (is_inf(value) && value > 0)
			std::cout << "+";
		std::cout << value;
		if (value == static_cast<long>(value))
			std::cout << ".0";
		std::cout << std::endl;
		std::cout << std::setprecision(default_p);
	}
	
	bool	is_nan(double d)
	{
		return (d != d);
	}
	
	bool	is_inf(double d)
	{
		return (d == std::numeric_limits<double>::infinity() || 
				d == -std::numeric_limits<double>::infinity());
	}
}
