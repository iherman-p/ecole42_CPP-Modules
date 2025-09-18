/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:09:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/12 16:59:35 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog& to_cpy)
		: Animal(to_cpy.type)
{
	std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog" << std::endl;	
}

void	Dog::makeSound() const
{
	std::cout << type << ": Woof!" << std::endl;
}
