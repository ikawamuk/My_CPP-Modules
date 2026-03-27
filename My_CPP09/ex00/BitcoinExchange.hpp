/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 04:56:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 06:18:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP_
# define BITCOINEXCHANGE_HPP_

# include "Date.hpp"
# include <string>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string& db_file_name);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();
		void	execute(const std::string& input_file_name) const;
	private:
		BitcoinExchange(void);
		std::map<Date, double>	data_base_;
};

#endif
