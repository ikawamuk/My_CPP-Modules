/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:10:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/22 01:58:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP_
# define ROBOTOMYREQUESTFORM_HPP_

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		explicit RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		void	execute(Bureaucrat const & executor) const;
		const std::string&	target(void) const;
	private:
		RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
		const std::string		target_;
};

#endif
