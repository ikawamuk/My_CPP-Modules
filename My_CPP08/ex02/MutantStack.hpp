/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:23:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/21 22:28:58 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP_
# define MUTANSTACK_HPP_

# include <stack>

template <typename T>
class MutanStack: public std::stack<T>
{
	
};

# include "MutantStack.tpp"

#endif
