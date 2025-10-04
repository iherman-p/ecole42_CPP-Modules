/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:41:36 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/30 21:11:30 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.cpp"
#include <string>
#include <limits>

static void	convertChar(const char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl; // may need to add an f to the end
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void	convertInt(const int i)
{
	std::cout << "char: ";
	if (i <= std::numeric_limits<char>::max() && i >= std::numeric_limits<char>::min())
		std::cout << static_cast<char>(i) << std::endl;
	else
		std::cout << "Impossible" << std::endl;

	std::cout << "int: " << i << std::endl;

	std::cout << "float: ";
	if (i <= std::numeric_limits<float>::max() && i >= std::numeric_limits<float>::min())
		std::cout << static_cast<float>(i) << std::endl;
	else
		std::cout << "Impossible" << std::endl;

	std::cout << "double: ";
	if (i <= std::numeric_limits<double>::max() && i >= std::numeric_limits<double>::min())
		std::cout << static_cast<double>(i) << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}

static void	convertFloat(const float f)
{
	std::cout << "char: ";
	if (f <= std::numeric_limits<char>::max() && f >= std::numeric_limits<char>::min())
		std::cout << static_cast<char>(f) << std::endl;
	else
		std::cout << "Impossible" << std::endl;

	std::cout << "int: ";
	if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
		std::cout << static_cast<int>(f) << std::endl;
	else
		std::cout << "Impossible" << std::endl;

	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void	convertDouble(const double d)
{
	std::cout << "char: ";
	if (f <= std::numeric_limits<char>::max() && f >= std::numeric_limits<char>::min())
		std::cout << static_cast<char>(f) << std::endl;
	else
		std::cout << "Impossible" << std::endl;

	std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
		std::cout << static_cast<int>(f) << std::endl;
	else
		std::cout << "Impossible" << std::endl;

	std::cout << "float: ";
	if (d <= std::numeric_limits<float>::max() && d >= std::numeric_limits<float>::min())
		std::cout << static_cast<float>(d) << std::endl;
	else
		std::cout << "Impossible" << std::endl;
	
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& data) const
{
	if (data.size() == 0)
	{
		std::cout << "Cannot convert empty input" << std::endl;
		return ;
	}

	try // try for int
	{
		convertInt(std::stoi(data));
		return ;
	}
	catch (std::exception& e) {}

	try // try for float
	{
		convertFloat(std::stof(data));
		return ;
	}
	catch (std::exception& e) {}

	try // try for double
	{
		convertDouble(std::stod(data));
		return ;
	}
	catch (std::exception& e) {}

	if (data.size() == 1) // try for char
	{
		convertChar(data[0]);
		return ;
	}
	std::cout << "Cannot convert data because it isn't a recognized scalar type: " << data << std::endl;
}
