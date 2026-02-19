/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:42 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/19 15:54:58 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	std::ifstream	file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
}