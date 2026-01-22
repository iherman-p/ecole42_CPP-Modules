/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:41:36 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/22 18:57:43 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

static void	convertChar(const signed char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void	convertInt(const int i)
{
	std::cout << "char: ";
	if (i > std::numeric_limits<signed char>::max() || i < std::numeric_limits<signed char>::min())
		std::cout << "Impossible" << std::endl;
	else if (i < ' ')
		std::cout << "Non printable" << std::endl; // This correctly catches control chars (0–31), but misses: 127 (DEL) → non printable Values above 126 → should be Impossible, not printable
	else
		std::cout << static_cast<signed char>(i) << std::endl;
	
	std::cout << "int: " << i << std::endl;

	std::cout << "float: ";
	if (i > std::numeric_limits<float>::max() || i < std::numeric_limits<float>::min())
		std::cout << "Impossible" << std::endl;		
	else
		std::cout << static_cast<float>(i) << std::endl;
	
	std::cout << "double: ";
	if (i > std::numeric_limits<double>::max() || i < std::numeric_limits<double>::min())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<double>(i) << std::endl;

}

static void	convertFloat(const float f)
{
	std::cout << "char: ";
	if (f > std::numeric_limits<signed char>::max() || f < std::numeric_limits<signed char>::min())
		std::cout << "Impossible" << std::endl;
	else if (f < ' ')
		std::cout << "Non printable" << std::endl;
	else
		std::cout << static_cast<signed char>(f) << std::endl;
		

	std::cout << "int: ";
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void	convertDouble(const double d) // fix
{
	std::cout << "char: ";
	if (d > std::numeric_limits<signed char>::max() || d < std::numeric_limits<signed char>::min())
		std::cout << "Impossible" << std::endl;
	else if (d < ' ')
		std::cout << "Non printable" << std::endl;
	else
		std::cout << static_cast<signed char>(d) << std::endl;

	std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << std::endl;
	
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& data)
{
	if (data.size() == 0)
	{
		std::cout << "Cannot convert empty input" << std::endl;
		return ;
	}

	// try for int
	{
		char* end;
		long value = std::strtol(data.c_str(), &end, 10);
		if (*end == '\0')
		{
			convertInt(static_cast<int>(value));
			return ;
		}
	}

	// try for float
	{
		char* end;
		double value = std::strtod(data.c_str(), &end);
		if (*end == '\0')
		{
			convertFloat(static_cast<float>(value));
			return ;
		}
	}

	// try for double
	{
		char* end;
		double value = std::strtod(data.c_str(), &end);
		if (*end == '\0')
		{
			convertDouble(value);
			return ;
		}
	}

	if (data.size() == 1)
	{
		convertChar(data[0]);
		return ;
	}

	std::cout << "Cannot convert data because it isn't a recognized scalar type: "
			  << data << std::endl;
}
