/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:26:53 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 16:03:32 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap		sceeter("Sceeter");
	ScavTrap		scoe("Scoe");
	ScavTrap		*sceeter_clone;

	sceeter_clone = new ScavTrap(sceeter);
	sceeter_clone->beRepaired(14);
	sceeter_clone->guardGate();
	delete sceeter_clone;

	std::cout << '\n';
	
	scoe.attack("Sceeter");
	sceeter.attack("Scoe");

	std::cout << '\n';

	scoe.beRepaired(100);
	sceeter.beRepaired(20);

	std::cout << '\n';

	scoe.takeDamage(14);
	sceeter.takeDamage(4800000);

	scoe.guardGate();
	sceeter.guardGate();
}