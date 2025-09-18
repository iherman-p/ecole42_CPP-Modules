/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:26:53 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/11 18:47:08 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	std::cout << "\nFragtrap tests: \n\n";
	FragTrap		freeter("Freeter");
	FragTrap		froe("Froe");
	FragTrap		*freeter_clone;

	freeter_clone = new FragTrap(freeter);
	freeter_clone->beRepaired(14);
	freeter_clone->highFivesGuys();
	delete freeter_clone;

	std::cout << '\n';
	
	froe.attack("Freeter");
	freeter.attack("Froe");

	std::cout << '\n';

	froe.beRepaired(100);
	freeter.beRepaired(20);

	std::cout << '\n';

	froe.takeDamage(14);
	freeter.takeDamage(4800000);

	froe.highFivesGuys();
	freeter.highFivesGuys();
}