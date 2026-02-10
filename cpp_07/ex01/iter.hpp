/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:51:05 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/10 17:40:12 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void	iter(T* arr, const std::size_t arrLen, const F& fct)
{
	for (std::size_t i = 0; i < arrLen; i++)
	{
		fct(arr[i]);
	}
}

// testing funcs

template <typename T>
void	print_arr(const T* arr, int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		std::cout << arr[i] << " ";
}

template <typename T>
void	increment_element(T& element)
{
	element++;
}

#endif // ITER_HPP