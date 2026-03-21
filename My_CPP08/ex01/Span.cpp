/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:56:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/21 21:55:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>

static void	throw_if_store_less_than_two(const std::vector<int> store);

Span::Span(void)
:N_(), store_()
{}

Span::Span(unsigned int n)
:N_(n), store_()
{}

Span::Span(const Span& other)
:N_(other.N_), store_(other.store_)
{}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		N_ = rhs.N_;
		store_ = rhs.store_;
	}
	return (*this);
}

Span::~Span(){}

unsigned int		Span::N(void) const
{
	return (N_);
}

std::vector<int>	Span::store(void) const
{
	return (store_);
}

void	Span::addNumber(int value)
{
	if (store_.size() >= N_)
		throw std::out_of_range("Span is full");
	store_.push_back(value);
}

template <typename T, typename Itr>
static T	generate_sorted(const Itr& begin, const Itr& end)
{
	T	sorted = T(begin, end);
	std::sort(sorted.begin(), sorted.end());
	return (sorted);
}

template <typename T, typename Itr>
static T	generate_difference_sequence(const Itr& begin, const Itr& end)
{
	T	diffs = T(begin, end);
	std::adjacent_difference(begin, end, diffs.begin());
	return (diffs);
}

unsigned long	Span::shortestSpan(void) const
{
	throw_if_store_less_than_two(store_);
	const std::vector<int>	sorted_store = generate_sorted<std::vector<int> >(store_.begin(), store_.end());
	const std::vector<int>	sorteds_diffs = generate_difference_sequence<std::vector<int> >(sorted_store.begin(), sorted_store.end());
	return (*std::min_element(sorteds_diffs.begin(), sorteds_diffs.end()));
}

unsigned long	Span::longestSpan(void) const
{
	throw_if_store_less_than_two(store_);
	return (*std::max_element(store_.begin(), store_.end()) - *std::min_element(store_.begin(), store_.end()));
}

static void	throw_if_store_less_than_two(const std::vector<int> store)
{
	if (store.size() < 2)
		throw std::logic_error("Not enough elements");
}
