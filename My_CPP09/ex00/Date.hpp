/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:07:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 23:40:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP_
# define DATE_HPP_

# include <string>
# include <ostream>
# include <ctime>

class Date
{
	public:
		Date(void);
		Date(const std::string& date_str);
		Date(const Date& other);
		Date&	operator=(const Date& rhs);
		~Date();
		time_t	time(void) const;
		std::string	to_str(void) const;
	private:
		time_t	time_;
};

std::ostream&	operator<<(std::ostream& os, const Date& date);
bool			operator<(const Date& lhs, const Date& rhs);
bool	operator>(const Date& lhs, const Date& rhs);
bool	operator>=(const Date& lhs, const Date& rhs);
bool	operator<=(const Date& lhs, const Date& rhs);

# endif
