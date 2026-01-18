/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:51:05 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 17:38:44 by iherman-         ###   ########.fr       */
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

#endif // ITER_HPP