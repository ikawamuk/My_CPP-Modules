/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 20:41:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/16 18:07:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cctype>

static bool	is_nan(double d);
static bool	is_inf(double d);
static void	error_case(void);
static void	convert_to_char(double value);
static void	convert_to_int(double value);
static void	convert_to_float(double value);
static void	convert_to_double(double value);

void	ScalarConverter::convert(const std::string& str)
{
	const char	*str_head = str.c_str();
	char		*endp;
	double	value = std::strtod(str_head, &endp);
	if (str_head == endp || *endp != '\0')
	{
		error_case();
		return ;
	}
	convert_to_char(value);
	convert_to_int(value);
	convert_to_float(value);
	convert_to_double(value);
}

static void	error_case(void)
{
	std::cout << "char: impossible" <<std::endl;
	std::cout << "int: impossible" <<std::endl;
	std::cout << "float: impossible" <<std::endl;
	std::cout << "double: impossible" <<std::endl;
}

static void	convert_to_char(double value)
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

static void	convert_to_int(double value)
{
	std::cout << "int: ";
	if (is_nan(value) || is_inf(value))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

static void	convert_to_float(double value)
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

static void	convert_to_double(double value)
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

static bool	is_nan(double d)
{
	return (d != d);
}

static bool	is_inf(double d)
{
	return (d == std::numeric_limits<double>::infinity() || 
			d == -std::numeric_limits<double>::infinity());
}
