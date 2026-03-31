/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 05:16:56 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/04/01 05:27:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <algorithm>

/*
比較回数カウントするか？
*/

namespace
{
	struct Element
	{
		Element(int value, const std::list<Element*> pairs):value_(value), pairs_(pairs) {}
		explicit Element(int value):value_(value) {}
		Element(const Element& other):value_(other.value_), pairs_(other.pairs_) {}
		Element&	operator=(const Element& rhs) {
			if (this != &rhs)
			{
				value_ = rhs.value_;
				pairs_ = rhs.pairs_;
			}
			return (*this);
		}
		bool		operator<(const Element& rhs) { return (value_ < rhs.value_); }
		bool		operator>(const Element& rhs) { return (value_ > rhs.value_); }
		void		setPair(Element* pair) { pairs_.push_back(pair); }
		Element*	getPair(void) const { return (pairs_.back()); }
		bool		hasPair(void) const { return (!pairs_.empty()); }
		void		popPair(void) { pairs_.pop_back(); }
		int						value_;
		std::list<Element*>	pairs_;
	};
	Element*	generateElement(int value);
	void		sort_recursive(std::list<Element*>& list);

	template <typename T>
	T&	list_at(std::list<T> list, std::size_t index)
	{
		typename std::list<T>::iterator it = list.begin();
		for (; index != 0; ++it)
			--index;
		return (*it);
	}
}

void	sort(std::list<int>& list)
{
	std::list<Element*>	sorting_list;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		sorting_list.push_back(generateElement(*it));
	sort_recursive(sorting_list);
	list.clear();
	for (std::list<Element*>::iterator it = sorting_list.begin(); it != sorting_list.end(); ++it)
	{
		list.push_back((*it)->value_);
		delete *it;
	}
}

namespace
{
	//void	print_list(std::list<Element*> v)
	//{
	//	for (std::list<Element*>::iterator it = v.begin(); it != v.end(); ++it)
	//		std::cerr << "velue:" << (*it)->value_ << std::endl;
	//}

	namespace
	{
		std::list<Element*>	play_tournament(std::list<Element*>& list);
		Element*				play_match(std::list<Element*>& list);
		std::list<Element*>	build_losers(std::list<Element*>& winners, std::list<Element*>& list);
		void					merge(std::list<Element*>& winners, std::list<Element*>& losers);
		void					binary_insert(std::list<Element*>& winners, Element* target);
		void					pop_pairs(std::list<Element*>& list);
	}

	Element*	generateElement(int value)
	{
		return (new Element(value));
	}

	void	sort_recursive(std::list<Element*>& list)
	{
		if (list.size() <= 1)
			return ;
		std::list<Element*>	winners = play_tournament(list);
		sort_recursive(winners);
		std::list<Element*>	losers = build_losers(winners, list);
		merge(winners, losers);
		list = winners;
		pop_pairs(list);
	}

	namespace
	{
		std::list<Element*>	play_tournament(std::list<Element*>& list)
		{
			std::list<Element*>	winners;
			while (list.size() >= 2)
				winners.push_back(play_match(list));
			return (winners);
		}

		Element*	play_match(std::list<Element*>& list)
		{
			Element*	first = list.back();
			list.pop_back();
			Element*	second = list.back();
			list.pop_back();
			first->setPair(second);
			second->setPair(first);
			return (*first > *second ? first : second);
		}

		std::list<Element*>	build_losers(std::list<Element*>& winners, std::list<Element*>& list)
		{
			std::list<Element*>	losers;
			for (std::list<Element*>::iterator it = winners.begin(); it != winners.end(); ++it)
				if ((*it)->hasPair())
					losers.push_back((*it)->getPair());
			if (!list.empty())
			{
				losers.push_back(list.back());
				list.pop_back();
			}
			return (losers);
		}

		struct JacobsthalSequence
		{
			JacobsthalSequence(std::size_t first, std::size_t second):n_minus_2(first), n_minus_1(second) {}
			std::size_t	getNext(void) {
				std::size_t	rev = n_minus_1 + 2 * n_minus_2;
				n_minus_2 = n_minus_1;
				n_minus_1 = rev;
				return (rev);
			}
			std::size_t	n_minus_2;
			std::size_t	n_minus_1;
		};

		void	merge(std::list<Element*>& winners, std::list<Element*>& losers)
		{
			winners.insert(winners.begin(), list_at(losers, 0));
			JacobsthalSequence	J_seq(1, 1);
			std::size_t	last_jacob = 1;
			while (last_jacob < losers.size())
			{
				std::size_t	curr_jacob = J_seq.getNext();
				for (std::size_t i = std::min(curr_jacob, losers.size()) - 1; last_jacob <= i; --i)
				{
					binary_insert(winners, list_at(losers, i));
				}
				last_jacob = curr_jacob;
			}
		}

		bool	is_smaller_element(Element* a, Element* b) { return (*a < *b); }

		void	binary_insert(std::list<Element*>& winners, Element* target)
		{
			std::list<Element*>::iterator it = std::lower_bound(winners.begin(), winners.end(), target, is_smaller_element);
			winners.insert(it, target);
		}

		void	pop_pairs(std::list<Element*>& list)
		{
			for (std::list<Element*>::iterator it = list.begin(); it != list.end(); ++it)
				if ((*it)->hasPair())
					(*it)->popPair();
		}
	}
}
