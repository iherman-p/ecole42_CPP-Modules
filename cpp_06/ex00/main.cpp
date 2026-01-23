/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:40:09 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/23 19:26:31 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main()
{
	std::cout << "\nValid:\n" << std::endl;
	ScalarConverter::convert("-1");
	std::cout << std::endl;
	ScalarConverter::convert("99999999999999999999999999999999");
	std::cout << std::endl;

	ScalarConverter::convert("100.7"); // does not print anything for char when it should
	std::cout << std::endl;
	ScalarConverter::convert(".5f");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;

	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("\t");
	std::cout << std::endl;

	/*std::cout << "\nInvalid:\n" << std::endl;
	ScalarConverter::convert("abc");
	std::cout << std::endl;
	ScalarConverter::convert("99999999999");
	std::cout << std::endl;
	ScalarConverter::convert("1.1.0");
	std::cout << std::endl;*/
}