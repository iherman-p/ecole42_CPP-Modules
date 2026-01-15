/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:35:17 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/15 16:11:50 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

template <typename T>
Array<T>::Array()
	: _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(size_t n)
	: _size(n)
{
	_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T>& other)
	: _size(other.size)
{
	_array = new T[other._size];
	for (size_t i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>&		Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] _array;
		_array = new T[other._size]
		_size = other._size;
		for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
T&			Array<T>::operator[] (size_t i)
{
	if (i <= _size)
	{
		return _array[i];
	}
	throw Array<T>::OutOfBoundAccess();
}

template <typename T>
const T&	Array<T>::operator[] (size_t i) const
{

}

template <typename T>
size_t		Array<T>::size(void) const
{
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundAccess::what() const throw()
{
	return "Exception: Out of bounds array access".c_str();
}