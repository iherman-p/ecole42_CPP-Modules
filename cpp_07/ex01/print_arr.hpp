/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:14:42 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/17 18:50:44 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ARR_HPP
# define PRINT_ARR_HPP

#include <iostream>

template <typename T>
void	print_arr(const T arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		std::cout << arr[i] << " ";
}

#endif // PRINT_ARR_HPP
