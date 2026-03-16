/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:32:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/16 19:18:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
# define WHATEVER_HPP_

template <typename T>
void	swap(T& a, T& b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return (a > b ? a : b);
}

#endif
