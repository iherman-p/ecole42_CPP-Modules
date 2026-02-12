/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:35:17 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/10 18:15:03 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other)
	: std::stack<T>(other)
{}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T>&		MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
	{
		std::stack<T>::operator=(other);
	}
	return *this;
}

template <typename T>
MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return c.begin();
}

template <typename T>
MutantStack<T>::iterator	MutantStack<T>::end()
{
	return c.end();
}

template <typename T>
MutantStack<T>::const_iterator	MutantStack<T>::cbegin() const
{
	return c.cbegin();
}

template <typename T>
MutantStack<T>::const_iterator	MutantStack<T>::cend() const
{
	return c.cend();
}

template <typename T>
MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return c.rbegin();
}

template <typename T>
MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return c.rend();
}

template <typename T>
MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin() const
{
	return c.crbegin();
}

template <typename T>
MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend() const
{
	return c.crend();
}

#endif // MUTANTSTACK_TPP