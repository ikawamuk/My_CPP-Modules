/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:49:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/22 02:04:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP_
# define INTERN_HPP_

# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& other);
		Intern&	operator=(const Intern& rhs);
		~Intern();
		static AForm	*makeForm(const std::string& form_name, const std::string& target);
};

struct FormTable
{
	std::string	form_name;
	AForm		*(*new_form)(const std::string&);
};

#endif
