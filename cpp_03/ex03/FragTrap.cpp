/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:27:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 15:11:02 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string new_name)
	: ClapTrap(new_name)
{
	std::cout << "FragTrap spawned with default constructor: " << new_name << std::endl;
	hp = 100;
	ep = 100;
	atk_dmg = 30;
}

FragTrap::FragTrap(const FragTrap &to_cpy)
	: ClapTrap(to_cpy)
{
	std::cout << "FragTrap spawned with copy constructor: " << this->name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroyed: " << this->name << std::endl;	
}

FragTrap&	FragTrap::operator=(const FragTrap& to_cpy)
{
	if (this != &to_cpy)
		ClapTrap::operator=(to_cpy);
	return *this;
}

void	FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap: attack: \n";

	if (hp == 0)
		std::cout << name << " is dead and cannot attack\n";
	else if (ep <= 0)
		std::cout << name << " tried to explode you, but forgot to bring backup grenades. >:(\n";
	else
	{
		std::cout << this->name << " throws a grenade at " << target << " for " << atk_dmg << " damage. >:D\n";
		ep--;
	}
	std::cout << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap: highFivesGuys: \n";

	if (hp == 0)
		std::cout << name << " is dead and cannot high five\n";
	else if (ep <= 0)
		std::cout << name << " just doesn't have the mental energy for this right now\n";
	else
	{
		std::cout << name << " extends their hand to give everybody a high five >:)\n";
		ep--;
	}
	std::cout << std::endl;
}
