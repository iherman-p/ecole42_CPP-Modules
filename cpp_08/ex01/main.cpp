/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:05:16 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/12 16:12:11 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int	main()
{
	Span	span(15);

	std::srand(static_cast<unsigned int>(std::time(0)));
	for (std::size_t i = 0; ; ++i)
	{
		try
		{
			int	num = std::rand() % 100000;
			span.addNumber(num);
			std::cout << "Added number: " << num << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
			break ;
		}
		
	}
	std::cout << "\nShortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
}
