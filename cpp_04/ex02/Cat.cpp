/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:09:33 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/12 16:26:21 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal("Cat")
{
	brain = new Brain("Kill all humans");
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(const Cat& to_cpy)
		: Animal("Cat")
{
	brain = new Brain(*to_cpy.brain->ideas);
	std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor called for Cat" << std::endl;
	delete brain;
}

void	Cat::makeSound() const
{
	std::cout << type << ": Mrrraw" << std::endl;
}
