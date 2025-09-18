/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:59:36 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/05 17:36:21 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	Harl	best_friend;
	int		complaint_level(0);
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
		return (1);
	while (complaint_level < 4 && levels[complaint_level].compare(std::string(argv[1])) != 0)
		complaint_level++;
	switch (complaint_level)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			best_friend.complain("DEBUG");
			std::cout << std::endl;
		}
		case 1:
		{
			std::cout << "[ INFO ]" << std::endl;
			best_friend.complain("INFO");
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout << "[ WARNING ]" << std::endl;
			best_friend.complain("WARNING");
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout << "[ ERROR ]" << std::endl;
			best_friend.complain("ERROR");
			std::cout << std::endl;
			break ;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
