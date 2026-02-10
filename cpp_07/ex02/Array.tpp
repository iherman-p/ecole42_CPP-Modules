/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:35:17 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/10 18:15:03 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array()
	: array_(NULL), size_(0)
{
}

template <typename T>
Array<T>::Array(std::size_t n)
	: array_(new T[n]()), size_(n)
{
}

template <typename T>
Array<T>::Array(const Array<T>& other)
	: array_(new T[other.size_]), size_(other.size_)
{
	for (std::size_t i = 0; i < size_; i++)
		array_[i] = other.array_[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] array_;
}

template <typename T>
Array<T>&		Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		T* new_array = new T[other.size_];
		for (std::size_t i = 0; i < other.size_; i++)
			new_array[i] = other.array_[i];

		delete[] array_;
		array_ = new_array;
		size_ = other.size_;
	}
	return *this;
}

template <typename T>
T&			Array<T>::operator[] (std::size_t i)
{
	if (i >= size_)
		throw Array<T>::OutOfBoundsAccess();
	return array_[i];
}

template <typename T>
const T&	Array<T>::operator[] (std::size_t i) const
{
	if (i >= size_)
		throw Array<T>::OutOfBoundsAccess();
	return array_[i];
}

template <typename T>
std::size_t		Array<T>::size() const
{
	return size_;
}

template <typename T>
const char* Array<T>::OutOfBoundsAccess::what() const throw()
{
	return "Out of bounds array access";
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& arr)
{
	for (std::size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << ' ';
	return out;
}
