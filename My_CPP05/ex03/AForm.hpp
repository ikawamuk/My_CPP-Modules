/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:37:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/12 10:19:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP_
# define AForm_HPP_

# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm
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
		class FormNotSignedException : public std::runtime_error
		{
			public:
				FormNotSignedException(const std::string& msg);
		};
							AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
		virtual				~AForm() = 0;
		void				beSign(const Bureaucrat& executor);
		virtual void		execute(const Bureaucrat& executor) const = 0;
		const std::string&	name(void) const;
		bool				is_signed(void) const;
		int					grade_to_sign(void) const;
		int					grade_to_execute(void) const;
	protected:
		void				throw_if_not_executable(Bureaucrat const & b) const;
	private:
		void				throw_if_higher_than_top_grade(int grade);
		void				throw_if_lower_than_top_grade(int grade);
		AForm(void);
		AForm&	operator=(const AForm& rhs);
		static const int	top_grade;
		static const int	bottom_grade;
		const std::string	name_;
		bool				is_signed_;
		const int			grade_to_sign_;
		const int			grade_to_execute_;
};

std::ostream&	operator<<(std::ostream& os, const AForm& fo);

#endif
