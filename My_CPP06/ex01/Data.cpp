/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:58:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 23:00:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
:data_()
{}

Data::Data(int data)
:data_(data)
{}

Data::Data(const Data& other)
:data_(other.data_)
{}

Data&	Data::operator=(const Data& rhs)
{
	if (this != &rhs)
		data_ = rhs.data_;
	return (*this);
}

Data::~Data()
{}
