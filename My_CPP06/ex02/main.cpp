/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:14:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 23:23:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inherit.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Base* ptr = generate();
	std::cout << "Identify by pointer: ";
	identify(ptr);
	std::cout << "Identify by reference: ";
	identify(*ptr);
	delete ptr;
	return 0;
}
