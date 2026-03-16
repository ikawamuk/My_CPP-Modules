/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:40:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/16 18:29:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP_
# define DATA_HPP_

struct Data
{
	int	data_;
	Data(void);
	explicit Data(int data);
	Data(const Data& other);
	Data& operator=(const Data& rhs);
	~Data();
};

#endif
