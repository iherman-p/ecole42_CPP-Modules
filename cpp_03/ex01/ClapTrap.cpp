/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:44:56 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 15:09:12 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string new_name)
	: name(new_name), hp(10), ep(10), atk_dmg(0)
{
	std::cout << "ClapTrap spawned with default constructor: " << new_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &to_cpy)
	: name(to_cpy.name), hp(to_cpy.hp),
	ep(to_cpy.ep), atk_dmg(to_cpy.atk_dmg)
{
	std::cout << "ClapTrap spawned with copy constructor: " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destroyed: " << this->name << std::endl;	
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& to_cpy)
{
	if (this == &to_cpy)
		return *this;
	this->atk_dmg = to_cpy.atk_dmg;
	this->ep = to_cpy.ep;
	this->hp = to_cpy.hp;
	this->name = to_cpy.name;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap: attack:\n";

	if (ep > 0 && hp > 0)
	{
		std::cout << this->name << " Hit " << target << " for " << atk_dmg << ". >:D\n";
		ep--;
	}
	else
		std::cout << name << " tried to attack, but failed >:(\n";
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap: takeDamage:\n";	

	std::cout << name << " took " << amount << " damage\n" << std::endl;
	hp -= amount;
	if (hp < 0)
		hp = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap: beRepaired:\n";

	if (ep > 0 && amount > 0 && hp > 0)
	{
		hp += amount;
		std::cout << name << " repaired themselves with " << amount << " amount :D\n";
		ep--;
	}
	else
		std::cout << name << " tried to repair, but failed :(\n";
	std::cout << std::endl;
}
