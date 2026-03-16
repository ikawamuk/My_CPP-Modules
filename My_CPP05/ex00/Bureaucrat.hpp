/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 00:39:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 15:34:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_

# include <string>
# include <stdexcept>

class Bureaucrat
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
		Bureaucrat(const std::string& name, int grade);
		virtual	~Bureaucrat();
		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				promote(void);
		void				demote(void);
	private:
							Bureaucrat(void);
		Bureaucrat&			operator=(const Bureaucrat& rhs);
		static void			throw_too_high_grade(void);
		static void			throw_too_low_grade(void);
		static const int	top_grade;
		static const int	bottom_grade;
		const std::string	name_;
		int					grade_;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& br);

#endif
