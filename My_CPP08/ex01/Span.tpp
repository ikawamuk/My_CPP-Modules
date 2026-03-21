/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:03:42 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/21 22:12:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP_
# define SPAN_TPP_

# include "Span.hpp"
# include <stdexcept>

template <typename Iterator>
void	Span::addNumber(Iterator begin, Iterator end)
{
	typename std::iterator_traits<Iterator>::difference_type dist = std::distance(begin, end);
	if (dist < 0)
		return;
	if (store_.size() + static_cast<unsigned int>(dist) > this->N_)
		throw std::out_of_range("Span: Not enough space to add this range");
	store_.insert(store_.end(), begin, end);
}

#endif
