/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:29:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/28 17:43:50 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void	swap(int& n1, int& n2)
{
	int tmp = n1;
	
	n1 = n2;
	n1 = tmp;
}

int	min(const int n1, const int n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

int	max(const int n1, const int n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}
