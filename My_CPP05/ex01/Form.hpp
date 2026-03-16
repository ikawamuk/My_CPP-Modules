/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:37:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 15:33:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
# define FORM_HPP_

# include <string>
# include <stdexcept>

class Bureaucrat;

class Form
{
	public:
		class GradeTooHighException: public std::runtime_error
		{
			public:
				GradeTooHighException(const std::string& msg);
		};
		class GradeTooLowException: public std::runtime_error
		{
			public:
				GradeTooLowException(const std::string& msg);
		};
		Form(const std::string& name, int grade_to_sign, int grade_to_execute);
		virtual	~Form();
		void				beSign(const Bureaucrat& b);
		const std::string&	name(void) const;
		bool				is_signed(void) const;
		int					grade_to_sign(void) const;
		int					grade_to_execute(void) const;
	private:
		static void			throw_if_higher_than_top_grade(int grade);
		static void			throw_if_lower_than_top_grade(int grade);
		Form(void);
		Form&	operator=(const Form& rhs);
		static const int	top_grade;
		static const int	bottom_grade;
		const std::string	name_;
		bool				is_signed_;
		const int			grade_to_sign_;
		const int			grade_to_execute_;
};

std::ostream&	operator<<(std::ostream& os, const Form& fo);

#endif
