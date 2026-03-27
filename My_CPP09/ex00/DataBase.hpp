/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:50:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 23:34:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP_
# define DATABASE_HPP_

# include "DataFile.hpp"
# include "Date.hpp"
# include <map>

class DataBase
{
	public:
		explicit DataBase(DataFile& data_file);
		DataBase(const DataBase& other);
		DataBase&	operator=(const DataBase& rhs);
		~DataBase();
		std::map<Date, double>	rates_by_date() const;
		double	find(const Date& date) const;
	private:
		DataBase(void);
		std::map<Date, double>	rates_by_date_;
};

#endif
