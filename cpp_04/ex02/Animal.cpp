/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:09:35 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/16 15:15:46 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
	: type("Undiscovered species")
{
	std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(std::string new_type)
	: type(new_type)
{
	std::cout << "Type constructor called for Animal" << std::endl;
}

Animal::Animal(Animal& to_cpy)
	:type(to_cpy.type)
{
	std::cout << "Copy constructor called for Animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor called for Animal" << std::endl;	
}
