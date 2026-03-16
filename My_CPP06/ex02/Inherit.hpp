/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inherit.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:09:54 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/14 23:13:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INHERIT_HPP_
# define INHERIT_HPP_

# include "Base.hpp"

class A: public Base
{};

class B: public Base
{};

class C: public Base
{};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
