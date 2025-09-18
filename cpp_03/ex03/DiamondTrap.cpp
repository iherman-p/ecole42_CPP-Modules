/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:18:56 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 15:50:43 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string new_name) :
	ClapTrap(new_name + "_clap_name"),
	ScavTrap(new_name),
	FragTrap(new_name)
{
	std::cout << "DiamondTrap spawned with default constructor: " << new_name << std::endl;
	DiamondTrap::name = new_name;
	hp = 100;
	ep = 50;
	atk_dmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &to_cpy) :
	ClapTrap(to_cpy),
	ScavTrap(to_cpy),
	FragTrap(to_cpy),
	name(to_cpy.DiamondTrap::name)
{
	std::cout << "DiamondTrap spawned with copy constructor: " << DiamondTrap::name << ", " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroyed: " << this->name << std::endl;	
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& to_cpy)
{
	if (this != &to_cpy)
	{
		ClapTrap::operator=(to_cpy);
		DiamondTrap::name = to_cpy.DiamondTrap::name;
	}
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Diamondtrap: whoAmI:\n";

	if (hp > 0)
		std::cout << name << " is dead and cannot contemplate their existence\n";
	else if (ep > 0)
		std::cout << name << " is tired and doesnt really care right now\n";
	else
	{
		std::cout << "Who am i...? I must be " << ScavTrap::name << ". No, wait, I'm " << this->name << '\n';
		ep--;
	}
	std::cout << std::endl;
}
