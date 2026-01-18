/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:01:51 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 17:40:41 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "util.hpp"

int	main()
{
	const int	array_size = 5;
	int			array_a[array_size] = {0, 0, 0, 0, 0};
	char		array_b[array_size] = {'A', 'A', 'A', 'A', 'A'};

	std::cout << "test 1:" << std::endl;

	print_arr(array_a, array_size);
	std::cout << std::endl;
	print_arr(array_b, array_size);
	std::cout << "\nafter increment func: " << std::endl;

	iter(array_a, array_size, increment_element);
	iter(array_b, array_size, increment_element);

	print_arr(array_a, array_size);
	std::cout << std::endl;
	print_arr(array_b, array_size);
	std::cout << std::endl;
}
