/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:28:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 23:28:44 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

std::string	trim(const std::string& s)
{
	size_t first = s.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";
	size_t last = s.find_last_not_of(" \t\r\n");
	return s.substr(first, (last - first + 1));
}
