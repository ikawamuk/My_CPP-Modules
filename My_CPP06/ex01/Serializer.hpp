/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:37:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/15 20:03:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP_
# define SERIALIZER_HPP_

# include "Data.hpp"

typedef unsigned long int uintptr_t;

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		Serializer(void);
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& rhs);
		virtual ~Serializer() = 0;
};

#endif
