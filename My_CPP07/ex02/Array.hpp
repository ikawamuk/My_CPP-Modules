/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:00:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2026/03/20 22:08:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP_
# define ARRAY_HPP_

# include <cstddef>
# include <exception>
# include <stdexcept>

template <typename T>
class Array
{
	public:
					Array(void);
					Array(unsigned int n);
					Array(const Array& other);
		Array&		operator=(const Array& rhs);
					~Array();
		std::size_t	size(void) const;
		T&			operator[](std::size_t index);
		const T&	operator[](std::size_t index) const;
	private:
		T			*elements_;
		std::size_t	size_;
};

template <typename T>
Array<T>::Array(void)
:elements_(NULL), size_(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
:elements_(NULL), size_(n)
{
	if (n == 0)
		return;
	elements_ = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other)
:elements_(NULL), size_(other.size_)
{
	if (size_ == 0)
		return;
	elements_ = new T[size_]();
	for (std::size_t i = 0; i < size_; ++i)
		elements_[i] = other.elements_[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this == &rhs)
		return (*this);
	delete [] elements_;
	elements_ = NULL;
	size_ = rhs.size_;
	if (size_ == 0)
		return (*this);
	elements_ = new T[size_]();
	for (std::size_t i = 0; i < size_; ++i)
		elements_[i] = rhs.elements_[i];
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] elements_;
}

template <typename T>
std::size_t Array<T>::size(void) const
{
	return (size_);
}

template <typename T>
T& Array<T>::operator[](std::size_t index)
{
	if (index >= size_)
		throw std::out_of_range("Array index out of bounds");
	return (elements_[index]);
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const
{
	if (index >= size_)
		throw std::out_of_range("Array index out of bounds");
	return (elements_[index]);
}

#endif
