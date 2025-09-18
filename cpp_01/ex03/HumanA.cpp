/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:58:25 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 16:15:52 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon)
	: _name(name), _weapon(weapon)
{
}

void	HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &new_weapon)
{
	_weapon = new_weapon;
}
