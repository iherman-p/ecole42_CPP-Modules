/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:33:27 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 17:35:06 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "print_arr.hpp"

int	main()
{
	const size_t	array_size = 10;
	Array<int> i_array(array_size);

	std::cout << "Array 1 before init: ";
	print_arr(i_array, array_size);
	std::cout << std::endl;
	
	for (size_t i = 0; i < array_size; i++)
		i_array[i] = i;

	Array<int> i_array2(i_array);
	Array<int> i_array3 = i_array;
	std::cout << "Array 1: ";
	print_arr(i_array, array_size);
	std::cout << '\n' << "Array 2 (copied via constructor): ";
	print_arr(i_array2, array_size);
	std::cout << '\n' << "Array 3 (copied via '=' overload): ";
	print_arr(i_array3, array_size);
	
	std::cout << "\n\nElement at index 5: " << i_array[5] << std::endl;

	try
	{
		std::cout << "Element at index " << array_size + 1 << ": " << i_array[array_size + 1];
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "Array size: " << i_array.size() << ", Provided size: " << array_size << std::endl;

	std::cout << "\nTesting empty char array: " << std::endl;
	Array<char> c_array;
	std::cout << "Size: " << c_array.size() << std::endl;
	
	try
	{
		std::cout << "Element at index 0: " << i_array[array_size + 1];
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	c_array = Array<char>(array_size);
	std::string msg = "Hey World!";
	for (size_t i = 0; i < array_size; i++)
		c_array[i] = msg[i];
	std::cout << "Char array after init: ";
	print_arr(c_array, array_size);
	std::cout << std::endl;
}
