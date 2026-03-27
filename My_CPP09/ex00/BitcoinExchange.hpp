/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 04:56:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 23:35:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP_
# define BITCOINEXCHANGE_HPP_

# include "DataBase.hpp"
# include "DataFile.hpp"
# include <fstream>
# include <string>

class BitcoinExchange
{
	public:
		explicit BitcoinExchange(DataFile& data_file);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();
		void		execute(const std::string& input_file_name) const;
		DataBase	data_base(void) const;
	private:
		BitcoinExchange(void);
		double		get_rate(const Date& date) const;
		DataBase	data_base_;
};

#endif
