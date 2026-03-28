/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:01:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/28 13:03:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>

#include <algorithm>
void	sort(std::vector<int>& vector)
{
	std::sort(vector.begin(), vector.end());
}

void	sort(std::list<int>& list)
{
	list.sort();
}
