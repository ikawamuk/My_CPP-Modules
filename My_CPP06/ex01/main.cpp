/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:00:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 23:07:12 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data	d(42);

	uintptr_t u = Serializer::serialize(&d);
	Data*	p = Serializer::deserialize(u);
	std::cout << "&d:" << &d << std::endl;
	std::cout << "p:" << p << std::endl;
	std::cout << "d.data:" << d.data_ << std::endl;
	std::cout << "p->data:" << p->data_ << std::endl;
}
