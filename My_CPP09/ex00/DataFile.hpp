/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataFile.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:49:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/27 20:26:25 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATAFILE_HPP_
# define DATAFILE_HPP_

# include <string>
# include <fstream>

class DataFile
{
	public:
		explicit DataFile(const std::string& file_name);
		~DataFile();
		std::string	name(void) const;
		bool		get_line(std::string& buf);
	private:
		DataFile(void);
		DataFile(const DataFile& other);
		DataFile&	operator=(const DataFile& rhs);
		std::string		name_;
		std::ifstream	ifs_;
};

#endif
