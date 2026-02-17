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
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return std::stack<T>::c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const
{
	return std::stack<T>::c.rend();
}

#endif // MUTANTSTACK_TPP