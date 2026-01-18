/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:28:49 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 17:43:11 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main()
{
	int	a = 1;
	int	b = 2;
	int	c = 3;

	swap(a, b);
	std::cout << min(a, b) << std::endl;
	std::cout << max(a, c) << std::endl;
}
