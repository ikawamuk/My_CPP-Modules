/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:50:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 20:26:37 by ikawamuk         ###   ########.fr       */
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
	private:
		DataBase(void);
		std::map<Date, double>	db_;
};

#endif
