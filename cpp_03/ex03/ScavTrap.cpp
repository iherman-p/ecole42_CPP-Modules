/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:27:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 15:10:14 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string new_name)
	: ClapTrap(new_name)
{
	std::cout << "ScavTrap spawned with default constructor: " << new_name << std::endl;
	hp = 100;
	ep = 50;
	atk_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &to_cpy)
			: ClapTrap(to_cpy)
{
	std::cout << "ScavTrap spawned with copy constructor: " << this->name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroyed: " << this->name << std::endl;	
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& to_cpy)
{
	if (this != &to_cpy)
		ClapTrap::operator=(to_cpy);
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap: attack:\n";

	if (hp == 0)
		std::cout << name << " is dead and cannot attack\n";
	else if (ep <= 0)
		std::cout << name << " tried to attack, but ran out of garbage to throw. >:(\n";
	else
	{
		std::cout << this->name << " scratches " << target << " using some garbage for " << atk_dmg << " damage. >:D\n";
		ep--;
	}
	std::cout << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap: guardGate:\n";

	if (hp == 0)
		std::cout << name << " is dead and cannot enter gate keeper mode\n";
	else if (ep <= 0)
		std::cout << name << " cannot enter GATE KEEPER MODE! :(\n";
	else
	{
		std::cout << name << " has entered GATE KEEPER MODE! >:O\n";
		ep--;
	}
	std::cout << std::endl;
}
