/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:10:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 19:03:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP_
# define ROBOTOMYREQUESTFORM_HPP_

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		void	execute(Bureaucrat const & executor) const;
		const std::string&	target(void) const;
	private:
		RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
		const std::string		target_;
};

#endif
