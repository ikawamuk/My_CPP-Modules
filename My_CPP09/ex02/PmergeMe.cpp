/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 09:43:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/28 13:01:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

void	sort(std::vector<int>& vector);
void	sort(std::list<int>& list);

int	*convert_to_int_arr(char **str_arr, int size)
{
	int *sequence = new int[size];
	for (int i = 0; i < size; ++i)
	{
		sequence[i] = std::atoi(str_arr[i]);
		if (sequence[i] < 0)
		{
			delete[] sequence;
			throw std::invalid_argument("negative number is not valid");
		}
	}
	return (sequence);
}

template <typename SequenceContainer>
double	measure_sorting(char **str_arr, int size)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	int	*sequence = convert_to_int_arr(str_arr, size);
	SequenceContainer	c(sequence, sequence + size);
	delete[] sequence;
	sort(c);
	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	return (seconds * 1e6 + microseconds);
}

template <typename Iterator>
void	write_sequence(Iterator begin, Iterator end)
{
	if (begin != end)
	{
		std::cout << *begin;
		while (++begin != end)
			std::cout << " " << *begin;
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(void)
{}

PmergeMe::PmergeMe(char **int_strs, int size)
:str_arr_(int_strs), size_(size)
{}

PmergeMe::PmergeMe(const PmergeMe& other)
:str_arr_(other.str_arr_), size_(other.size_)
{}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		str_arr_ = rhs.str_arr_;
		size_ = rhs.size_;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}

void	PmergeMe::execute(void)
{
	double	vector_time = measure_sorting<std::vector<int> >(str_arr_, size_);
	double	list_time = measure_sorting<std::list<int> >(str_arr_, size_);
	int	*sequence = convert_to_int_arr(str_arr_, size_);
	std::cout << "Before:\t";
	write_sequence(sequence, sequence + size_);
	std::sort(sequence, sequence + size_);
	std::cout << "After:\t";
	write_sequence(sequence, sequence + size_);
	std::cout << "Time to process a range of " << size_ 
	<< "elements with std::vector : " << vector_time << " us" << std::endl;
	std::cout << "Time to process a range of " << size_ 
	<< "elements with std::list : " << list_time << " us" << std::endl;
	delete[] sequence;
}

