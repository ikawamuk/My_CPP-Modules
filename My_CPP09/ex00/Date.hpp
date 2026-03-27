/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:07:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 22:31:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP_
# define DATE_HPP_

# include <string>
# include <ostream>

class Date
{
	public:
		Date(void);
		Date(const std::string& date_str);
		Date(const Date& other);
		Date&	operator=(const Date& rhs);
		~Date();
		unsigned int	year(void) const;
		unsigned int	month(void) const;
		unsigned int	day(void) const;
	private:
		unsigned int	year_;
		unsigned int	month_;
		unsigned int	day_;
};

std::ostream&	operator<<(std::ostream& os, const Date& date);

# endif
