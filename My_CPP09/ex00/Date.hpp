/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 05:07:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 05:12:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP_
# define DATE_HPP_

# include <string>

class Date
{
	public:
		Date(void);
		Date(const std::string& date);
		Date(const Date& other);
		Date&	operator=(const Date& rhs);
		~Date();
	private:
		unsigned int	year;
		unsigned char	month;
		unsigned char	day;
};

# endif
