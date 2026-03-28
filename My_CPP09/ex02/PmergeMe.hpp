/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 09:43:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/28 12:35:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP_
# define PMERGEME_HPP_

# include <vector>
# include <list>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(char **int_strs, int size);
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& rhs);
		~PmergeMe();
		void	execute(void);
	private:
		char	**str_arr_;
		int		size_;
		
};

#endif
