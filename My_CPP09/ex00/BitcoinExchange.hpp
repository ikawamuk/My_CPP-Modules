/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:05:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/28 03:45:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP_
# define BITCOINEXCHANGE_HPP_

# include <string>
# include <map>
# include <ctime>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string& data_file_name);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();
		void	execute(const std::string& input_file_name) const;
	private:
		BitcoinExchange(void);
		std::map<std::time_t, double>	data_base_;
};

#endif
