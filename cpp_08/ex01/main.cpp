/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:05:16 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/17 15:42:50 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

static int process_input(std::string msg = "")
{
    int user_input;

	if (!msg.empty())
		std::cout << msg << std::endl;
	while (true)
    {
        if (std::cin >> user_input)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return user_input;
        }

        std::cout << "Please provide a valid number:" << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int	main()
{
	int max_elements;
	while (true)
	{
		max_elements = process_input("Provide max elements:");
		if (max_elements > 1)
			break ;
		std::cout << "max elements must be at least 2" << std::endl;
	}

	Span	span(max_elements);

	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "Adding numbers..." << std::endl;
	for (std::size_t i = 0; i < span.maxSize(); ++i)
	{
		int	num = std::rand() % 100000;
		span.addNumber(num);
	}
	std::cout << "\nShortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;

	for (Span::iterator it = span.begin(); it != span.end(); ++it)
	{
		*it = (*it % 16);
	}
	std::cout << "Shortest after iterator: " << span.shortestSpan() << std::endl;
	std::cout << "Longest after iterator: " << span.longestSpan() << std::endl;
}
