/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:49:52 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/05 16:28:07 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
	: _name("Choom")
{
	std::cout << "Default constructor called for Zombie" << std::endl;
}

Zombie::Zombie(const std::string &name)
	: _name(name)
{
	std::cout << "Name constructor called for Zombie: " << name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " has died... again :(" << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void	Zombie::setName(const std::string &new_name)
{
	this->_name = new_name;
}
