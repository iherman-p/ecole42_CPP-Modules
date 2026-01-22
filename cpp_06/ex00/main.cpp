/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:40:09 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/22 18:49:50 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main()
{
	ScalarConverter::convert("-1");
	std::cout << std::endl;
	ScalarConverter::convert("1.7"); // does not print anything for char when it should
	std::cout << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;
}