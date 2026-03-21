/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:46:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/22 01:58:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP_
# define PRESIDENTIALPARDONFORM_HPP_

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		explicit PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		void	execute(Bureaucrat const & executor) const;
		const std::string&	target(void) const;
	private:
		PresidentialPardonForm(void);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);
		const std::string		target_;
};

#endif
