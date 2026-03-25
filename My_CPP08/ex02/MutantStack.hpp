/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:23:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/25 21:22:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP_
# define MUTANSTACK_HPP_

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& rhs);
		~MutantStack();
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		iterator				begin(void);
		iterator				end(void);
		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);
};

# include "MutantStack.tpp"

#endif
