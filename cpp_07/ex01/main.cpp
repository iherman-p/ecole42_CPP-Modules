/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:01:51 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/10 17:39:41 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int	main()
{
	const int	kArraySize = 5;
	int			array_a[kArraySize] = {0, 0, 0, 0, 0};
	char		array_b[kArraySize] = {'A', 'A', 'A', 'A', 'A'};

	std::cout << "test 1:" << std::endl;

	print_arr(array_a, kArraySize);
	std::cout << std::endl;
	print_arr(array_b, kArraySize);
	std::cout << "\nafter increment func: " << std::endl;

	iter(array_a, kArraySize, increment_element<int>);
	iter(array_b, kArraySize, increment_element<char>);

	print_arr(array_a, kArraySize);
	std::cout << std::endl;
	print_arr(array_b, kArraySize);
	std::cout << std::endl;

	std::cout << "\nafter incrementing 3 elements: " << std::endl;
	iter(array_a, 3, increment_element<int>);
	iter(array_b, 3, increment_element<char>);

	print_arr(array_a, kArraySize);
	std::cout << std::endl;
	print_arr(array_b, kArraySize);
	std::cout << std::endl;
}
