/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:58:37 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 16:15:42 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
	: _type("random object")
{
}

Weapon::Weapon(const std::string &type)
	: _type(type)
{
}

const std::string	&Weapon::getType() const
{
	return _type;
}

void	Weapon::setType(const std::string &new_type)
{
	_type = new_type;
}
