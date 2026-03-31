/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:01:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/04/01 05:06:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>


/*
比較回数カウントするか？
*/

namespace
{
	struct Element
	{
		Element(int value, const std::vector<Element*> pairs):value_(value), pairs_(pairs) {}
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
		std::vector<Element*>	pairs_;
	};
	Element*	generateElement(int value);
	void		sort_recursive(std::vector<Element*>& vector);
}

#include <algorithm>
#include <iostream>
void	sort(std::vector<int>& vector)
{
	std::vector<Element*>	sorting_vector;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		sorting_vector.push_back(generateElement(*it));
	sort_recursive(sorting_vector);
	vector.clear();
	for (std::vector<Element*>::iterator it = sorting_vector.begin(); it != sorting_vector.end(); ++it)
	{
		std::cout << "final value:" << (*it)->value_ << std::endl;
		vector.push_back((*it)->value_);
		delete *it;
	}
}

namespace
{
	void	print_vector(std::vector<Element*> v)
	{
		for (std::vector<Element*>::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << "velue:" << (*it)->value_ << std::endl;
	}

	namespace
	{
		std::vector<Element*>	play_tournament(std::vector<Element*>& vector);
		Element*				play_match(std::vector<Element*>& vector);
		std::vector<Element*>	build_losers(std::vector<Element*>& winners, std::vector<Element*>& vector);
		void					merge(std::vector<Element*>& winners, std::vector<Element*>& losers);
		void					binary_insert(std::vector<Element*>& winners, Element* target);
		void					pop_pairs(std::vector<Element*>& vector);
	}

	Element*	generateElement(int value)
	{
		return (new Element(value));
	}

	void	sort_recursive(std::vector<Element*>& vector)
	{
		if (vector.size() <= 1)
			return ;
		std::vector<Element*>	winners = play_tournament(vector);
		sort_recursive(winners);
		print_vector(winners);
		std::vector<Element*>	losers = build_losers(winners, vector);
		merge(winners, losers);
		vector = winners;
		pop_pairs(vector);
	}

	namespace
	{
		std::vector<Element*>	play_tournament(std::vector<Element*>& vector)
		{
			std::vector<Element*>	winners;
			while (vector.size() >= 2)
				winners.push_back(play_match(vector));
			return (winners);
		}

		Element*	play_match(std::vector<Element*>& vector)
		{
			Element*	first = vector.back();
			vector.pop_back();
			Element*	second = vector.back();
			vector.pop_back();
			first->setPair(second);
			second->setPair(first);
			return (*first > *second ? first : second);
		}

		std::vector<Element*>	build_losers(std::vector<Element*>& winners, std::vector<Element*>& vector)
		{
			std::vector<Element*>	losers;
			for (std::vector<Element*>::iterator it = winners.begin(); it != winners.end(); ++it)
				if ((*it)->hasPair())
					losers.push_back((*it)->getPair());
			if (!vector.empty())
			{
				losers.push_back(vector.back());
				vector.pop_back();
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

		void	merge(std::vector<Element*>& winners, std::vector<Element*>& losers)
		{
			winners.insert(winners.begin(), losers.at(0));
			JacobsthalSequence	J_seq(1, 1);
			std::size_t	last_jacob = 1;
			while (last_jacob < losers.size())
			{
				std::size_t	curr_jacob = J_seq.getNext();
				for (std::size_t i = std::min(curr_jacob, losers.size()) - 1; last_jacob <= i; --i)
				{
					binary_insert(winners, losers.at(i));
				}
				last_jacob = curr_jacob;
			}
		}

		bool	is_smaller_element(Element* a, Element* b) { return (*a < *b); }

		void	binary_insert(std::vector<Element*>& winners, Element* target)
		{
			std::vector<Element*>::iterator it = std::lower_bound(winners.begin(), winners.end(), target, is_smaller_element);
			winners.insert(it, target);
		}

		void	pop_pairs(std::vector<Element*>& vector)
		{
			for (std::vector<Element*>::iterator it = vector.begin(); it != vector.end(); ++it)
				if ((*it)->hasPair())
					(*it)->popPair();
		}
	}
}

#include <stdexcept>
#include <iostream>
#include <cstdlib>

void	sort(std::vector<int>& vector);
void	sort(std::list<int>& list);
template <typename Container>
void test_sort(Container c)
{
	sort(c);
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it)
	{
		typename Container::iterator	next = it;
		++next;
		if (next == c.end())
			break;
		if (*it > *next)
			throw std::logic_error("sort function is incorrect");
	}
}

void	test_sort_vector(int *sequence, int size)
{
	try
	{
		test_sort<std::vector<int> >(std::vector<int>(sequence, sequence + size));
	}
	catch(const std::exception&)
	{
		std::cerr << "void	sort(std::vector<int>&) is wrong" << std::endl;
		throw ;
	}
	std::cout << "vector OK" << std::endl;
}

void	test_sort_list(int *sequence, int size)
{
	try
	{
		test_sort<std::list<int> >(std::list<int>(sequence, sequence + size));
	}
	catch(const std::exception&)
	{
		std::cerr << "void	sort(std::list<int>&) is wrong" << std::endl;
		throw ;
	}
	std::cout << "list OK" << std::endl;
}

int		*convert_to_int_arr(char **str_arr, int size);
void	test(int numbers[], int size);
int	main(int argc, char *argv[])
{
	for (int size = 1; size < 100; ++size)
	{
		int	*numbers = new int[size];
		for (int i = 0; i < size; ++i)
			numbers[i] = std::rand() % 101;
		test(numbers, size);
		delete[] numbers;
	}
}

void	test(int numbers[], int size)
{
	try
	{
		test_sort_vector(numbers, size);
		test_sort_list(numbers, size);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	std::cout << "[OK] size:" << size << std::endl;
}
