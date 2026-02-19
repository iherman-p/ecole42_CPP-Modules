/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:05:16 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/18 16:09:55 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <limits>

static int process_input()
{
    int user_input;

    while (true)
    {
        if (std::cin >> user_input)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return user_input;
        }

        std::cout << "Please provide a valid number" << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int	main()
{
	std::vector<int>	v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::cout << "Provide a number to search for: " << std::endl;
	int					num = process_input();

	std::vector<int>::iterator	found = easyfind(v, num);

	if (found != v.end())
		std::cout << "found: " << *found << std::endl;
	else
		std::cout << "Could not find number: " << num << std::endl;
}
