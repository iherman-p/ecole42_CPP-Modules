/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:42 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/19 21:51:34 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

void	parse_log(BitcoinExchange& exchange_log)
{
	
}

int main(int argc, char* argv[])
{
	(void) argc;

	BitcoinExchange	exchange_log;
	std::ifstream	file(argv[1]);

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	parse_log(exchange_log);
	std::cout << exchange_log.findClosest();
}