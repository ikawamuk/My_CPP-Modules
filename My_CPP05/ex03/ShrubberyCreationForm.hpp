/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:36:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 19:59:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP_
# define SHRUBBERYCREATIONFORM_HPP_

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		void	execute(Bureaucrat const & executor) const;
		const std::string&	target(void) const;
	private:
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
		const std::string		target_;
};

#endif
