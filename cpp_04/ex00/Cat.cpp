/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:09:33 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/12 16:59:41 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat& to_cpy)
		: Animal(to_cpy.type)
{
	std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called for Cat" << std::endl;	
}

void	Cat::makeSound() const
{
	std::cout << type << ": Mrrraw" << std::endl;
}
