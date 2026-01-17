/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:51:05 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/17 18:45:00 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T>
void	iter(T arr[], const int arrLen, void(*fct)(T&))
{
	if (fct == NULL)
		return ;
	for (int i = 0; i < arrLen; i++)
	{
		fct(arr[i]);
	}
}

template <typename T>
void	increment_element(T& element)
{
	element++;
}

#endif // ITER_HPP