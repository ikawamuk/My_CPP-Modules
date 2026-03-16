/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_template.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 19:50:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/16 19:52:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_TEMPLATE_HPP
# define TEST_TEMPLATE_HPP

# include <iostream>

template <typename T>
void	print_T_address(const T& val)
{
	std::cout << "argument's adddress: " << &val << std::endl;
}

#endif
