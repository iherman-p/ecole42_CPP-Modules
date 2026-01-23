/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:41:36 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/23 19:27:17 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>

static void	convertChar(const signed char c)
{
	std::cout << "char: ";
	if (c < ' ' || c >= 127)
		std::cout << "Non printable" << std::endl;
	else
		std::cout << c << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void	convertInt(const long i)
{
	std::cout << "char: ";
	if (i > std::numeric_limits<signed char>::max()
	 || i < std::numeric_limits<signed char>::min())
		std::cout << "Impossible" << std::endl;
	else if (i < ' ' || i >= 127)
		std::cout << "Non printable" << std::endl;
	else
		std::cout << static_cast<signed char>(i) << std::endl;

	std::cout << "int: ";
	if (i > std::numeric_limits<int>::max()
	 || i < std::numeric_limits<int>::min())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(i) << std::endl;

	std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;

	std::cout << "double: "<< static_cast<double>(i) << std::endl;
}

static void	convertFloat(const float f)
{
	if (std::isnan(f) || std::isinf(f))
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (f > std::numeric_limits<signed char>::max()
	 || f < std::numeric_limits<signed char>::min())
		std::cout << "Impossible" << std::endl;
	else if (f < ' ' || f >= 127)
		std::cout << "Non printable" << std::endl;
	else
		std::cout << static_cast<signed char>(f) << std::endl;

	std::cout << "int: ";
	if (f > std::numeric_limits<int>::max()
	 || f < std::numeric_limits<int>::min())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void	convertDouble(const double d)
{
	if (std::isnan(d) || std::isinf(d))
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << std::endl;
		std::cout << "double: " << d << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (d > std::numeric_limits<signed char>::max()
	 || d < std::numeric_limits<signed char>::min())
		std::cout << "Impossible" << std::endl;
	else if (d < ' ' || d >= 127)
		std::cout << "Non printable" << std::endl;
	else
		std::cout << static_cast<signed char>(d) << std::endl;

	std::cout << "int: ";
	if (d > std::numeric_limits<int>::max()
	 || d < std::numeric_limits<int>::min())
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& data)
{
	if (data.empty())
	{
		std::cout << "Cannot convert empty input" << std::endl;
		return ;
	}

	/* char */
	if (data.size() == 1 && !std::isdigit(data[0]))
	{
		convertChar(data[0]);
		return ;
	}

	/* int */
	{
		char	*end;
		long	value;

		errno = 0;
		value = std::strtol(data.c_str(), &end, 10);

		if (*end == '\0' && errno != ERANGE)
		{
			convertInt(value);
			return ;
		}
	}

	/* float / double */
	{
		char	*end;
		double	value = std::strtod(data.c_str(), &end);

		if (*end == '\0')
		{
			convertDouble(value);
			return ;
		}
		else if (*end == 'f' && end == &data[0] + data.size() - 1)
		{
			convertFloat(value);
			return ;
		}
	}

	std::cout << "Cannot convert data because it isn't a recognized scalar type: "
				<< data << std::endl;
}
