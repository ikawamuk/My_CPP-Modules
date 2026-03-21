/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:51:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/21 22:04:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP_
# define SPAN_HPP_

# include <vector>

class Span
{
	public:
		Span(void);
		Span(const unsigned int n);
		Span(const Span& other);
		Span&	operator=(const Span& rhs);
		~Span();
		unsigned int		N(void) const;
		std::vector<int>	store(void) const;
		void				addNumber(int value);
		template <typename Iterator>
		void				addNumber(Iterator begin, Iterator end);
		unsigned long		shortestSpan(void) const;
		unsigned long		longestSpan(void) const;
	private:
		std::vector<int>	generate_sort_store(void) const;
		unsigned int		N_;
		std::vector<int>	store_;
};

# include "Span.tpp"

# endif
