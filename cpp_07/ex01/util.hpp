/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:14:42 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 17:38:36 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
# define UTIL_HPP

#include <iostream>

template <typename T>
void	print_arr(const T arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		std::cout << arr[i] << " ";
}

template <typename T>
void	increment_element(T& element)
{
	element++;
}

#endif // UTIL_HPP
