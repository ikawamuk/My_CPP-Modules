/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:42:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/16 19:54:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP_
# define ITER_HPP_

# include <cstddef>

template <typename T, typename F>
void	iter(T* array, const std::size_t len, F func)
{
	for (std::size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif
