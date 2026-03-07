/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:42 by iherman-          #+#    #+#             */
/*   Updated: 2026/03/07 15:45:38 by iherman-         ###   ########.fr       */
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
			continue ;
		}

		try
		{
			exchange_log.addIndex(date.c_str(), value);
		}
		catch (const std::exception& e)
		{
		}
	}
	return exchange_log;
}

void	convert_input(std::ifstream& input_file, BitcoinExchange& exchange_log)
{
	std::string	line;
	const float	kAmountLimitUpper = 1000;

	std::getline(input_file, line);
	if (line != "date | value")
	{
		std::cerr << "Error: Missing header" << std::endl;
		return ;
	}
	while (std::getline(input_file, line))
	{
		size_t					pos = line.find(" | ");
		BitcoinExchange::Date	date;
		float					amount;
		char*					end;

		if (pos != std::string::npos)
		{
			try
			{
				date = BitcoinExchange::Date(line.substr(0, pos));
				amount = std::strtof(line.substr(pos + 3).c_str(), &end);
				if (amount < 0)
					throw std::runtime_error("Value cannot be negative");
				if (amount > kAmountLimitUpper)
					throw std::runtime_error("Value cannot be higher than 1000");
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
				continue ;
			}
		}

		if (pos == std::string::npos || *end || !line[pos + 3])
		{
			std::cerr << "Malformed line: " << line << std::endl;
			continue ;
		}

		std::map<BitcoinExchange::Date,float>::const_iterator it;
		it = exchange_log.getClosestDate(date);

		if (it == exchange_log.end())
			std::cerr << "Could not find date in database: " << date << std::endl;
		else
			std::cout << it->first << " => " << amount << " = " << amount * it->second << std::endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expected singular input file" << std::endl;
		return 1;
	}

	std::ifstream	input_file(argv[1]);

	if (!input_file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange	exchange_log = parse_log();
	convert_input(input_file, exchange_log);
}
