/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:41:36 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/26 18:26:18 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>

template <typename T>
static void	printChar(T num)
{
	std::cout << "char: ";
	if (num > std::numeric_limits<signed char>::max()
		|| num < std::numeric_limits<signed char>::min()
		|| num != num)
		std::cout << "impossible" << std::endl;
	else if (num < ' ' || num >= 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<signed char>(num) << std::endl;
}

template <typename T>
static void	printInt(T num)
{
	std::cout << "int: ";
	if (num > std::numeric_limits<int>::max()
		|| num < std::numeric_limits<int>::min()
		|| num != num)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<signed int>(num) << std::endl;
}

template <typename T>
static void	printFloat(T num)
{
	std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(num) << 'f' <<  std::endl;
}

template <typename T>
static void	printDouble(T num)
{
	std::cout << "double: "<< std::setprecision(1) << std::fixed << static_cast<double>(num) << std::endl;
}

static void printInvalid()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible" << std::endl;
}


template <typename T>
static void	convertType(const T type)
{
	printChar(type);
	printInt(type);
	printFloat(type);
	printDouble(type);
}

void ScalarConverter::convert(const std::string& data)
{
	if (data.empty())
	{
		std::cout << "Cannot convert empty input" << std::endl;
		return ;
	}

	/* char */
	if (data.size() == 1 && !std::isdigit(static_cast<unsigned char>(data[0])))
	{
		convertType(data[0]);
		return ;
	}

	/* int */
	{
		char	*end;
		long	value;

		errno = 0;
		value = std::strtol(data.c_str(), &end, 10);

		if (*end == '\0')
		{
			if (errno == ERANGE || value > std::numeric_limits<int>::max()
				|| value < std::numeric_limits<int>::min())
			{
				printInvalid();
				return ;
			}
			convertType(value);
			return ;
		}
	}

	/* float / double */
	{
		char	*end;
		double	value = std::strtod(data.c_str(), &end);

		if (*end == '\0')
		{
			convertType(value);
			std::cout.unsetf(std::ios::fixed);
			std::cout << std::setprecision(6);
			return ;
		}
		else if (*end == 'f' && end == &data[0] + data.size() - 1)
		{
			convertType(static_cast<float>(value));
			std::cout.unsetf(std::ios::fixed);
			std::cout << std::setprecision(6);
			return ;
		}
	}

	printInvalid();
}
