/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:01:21 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/05 16:18:50 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "iostream"

int	main()
{
	Zombie *horde = zombieHorde(10, "Paul");
	
	if (horde)
	{
		for (int i = 0; i < 10; i++)
			horde->announce();
		delete[] horde;
	}
}
