/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:26:53 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 15:58:43 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	DiamondTrap	deeter("Deeter");
	DiamondTrap	doe("Doe");
	DiamondTrap	*deeter_clone;

	deeter_clone = new DiamondTrap(deeter);

	std::cout << '\n'; // end of constructors

	deeter_clone->beRepaired(14);
	delete deeter_clone;
	
	doe.attack("Deeter");
	deeter.attack("Doe");

	doe.beRepaired(100);
	deeter.beRepaired(20);

	doe.takeDamage(14);
	deeter.takeDamage(4800000);

	doe.whoAmI();
	deeter.whoAmI();
}