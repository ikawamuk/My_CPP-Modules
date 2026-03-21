/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:27:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/21 18:41:50 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP_
# define EASYFIND_TPP_

# include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(const T &int_container, int value)
{
	return (std::find(int_container.begin(), int_container.end(), value));
}

template <typename T>
typename T::iterator	easyfind(T &int_container, int value)
{
	return (std::find(int_container.begin(), int_container.end(), value));
}

#endif
