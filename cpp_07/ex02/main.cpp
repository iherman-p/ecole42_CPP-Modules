/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:42:21 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/10 18:35:37 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <cstdlib>
#include <ctime>

#define MAX_VAL 750
void	provided_tests()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cout << "didn't save the same value!!" << std::endl;
        }
    }
    try
    {
        numbers[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
}

int	main()
{
	{
		const std::size_t	kArraySize = 15;
		Array<int>	arr1(kArraySize);

		for (std::size_t i = 0; i < arr1.size(); i++)
		{
			arr1[i] = i;
		}

		Array<int>	arr2 = Array<int>(arr1);

		std::cout << "arr1: " << arr1 << std::endl;
		std::cout << "arr2: "<< arr2 << std::endl;
	}

	{
		const std::size_t	kArraySize = 26;
		Array<char>	alphabet1(kArraySize);

		for (std::size_t i = 0; i < alphabet1.size(); i++)
		{
			alphabet1[i] = i + 'a';
		}

		Array<char>	alphabet2;
		alphabet2 = Array<char>(alphabet1);

		std::cout << "alphabet1: " << alphabet1 << std::endl;
		std::cout << "alphabet2: "<< alphabet2 << std::endl;
	}

	{
		const std::size_t	kArraySize = 10;
		Array<int>	arr(kArraySize);

		for (std::size_t i = 0; i < arr.size(); i++)
		{
			arr[i] = i;
		}

		std::cout << "Accesing alphabet at array size + 1" << std::endl;

		try
		{
			arr[arr.size() + 1] = 1;
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << '\n';
		}
	}

	std::cout << "\nProvided tests:" << std::endl;

	provided_tests();
}