/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:42 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/22 23:13:40 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

BitcoinExchange	parse_log()
{
	std::ifstream	exchange_log_file("data.csv");
	BitcoinExchange	exchange_log;

	std::string	line;
	if (!exchange_log_file.is_open())
	{
		std::cerr << "Error: could not open data.csv" << std::endl;
		exit(1);
	}
	while (std::getline(exchange_log_file, line))
	{
		std::string	date;
		float		value;
		size_t		pos = line.find(',');
		char*		end;

		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			value = std::strtof(line.substr(pos + 1).c_str(), &end);
		}

		if (pos == std::string::npos || *end)
		{
			// std::cerr << "Malformed line: " << line << std::endl;
			continue ;
		}

		try
		{
			exchange_log.addIndex(date.c_str(), value);
		}
		catch (const std::exception& e)
		{
			// std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	return exchange_log;
}

void	convert_input(std::ifstream& input_file, BitcoinExchange& exchange_log)
{
	std::string	line;
	while (std::getline(input_file, line))
	{
		BitcoinExchange::Date	date;
		float					amount;
		size_t					pos = line.find(',');
		char*					end;

		if (pos != std::string::npos)
		{
			try
			{
				date = BitcoinExchange::Date(line.substr(0, pos));
				amount = std::strtof(line.substr(pos + 1).c_str(), &end);
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
				continue ;
			}
		}

		if (pos == std::string::npos || *end)
		{
			std::cerr << "Malformed line: " << line << std::endl;
			continue ;
		}

		std::map<BitcoinExchange::Date,float>::const_iterator it;
		it = exchange_log.getClosestDate(date);

		std::cout << it->first << " => " << amount << " = " << amount * it->second << std::endl;
	}
}

int main(int argc, char* argv[])
{
	(void) argc;

	std::ifstream	input_file(argv[1]);

	if (!input_file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange	exchange_log = parse_log();
	convert_input(input_file, exchange_log);
}
