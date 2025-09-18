/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:56:36 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/16 15:13:12 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	ideas = new std::string[100];
	std::cout << "Default constructor called for Brain" << std::endl;
	for (int i(0); i < 100; i++)
		this->ideas[i] = "Very good idea";	
}

Brain::Brain(std::string new_idea)
{
	ideas = new std::string[100];
	std::cout << "Idea initializer constructor called for Brain" << std::endl;
	for (int i(0); i < 100; i++)
		this->ideas[i] = new_idea;	
}


Brain::Brain(const Brain& to_cpy)
{
	ideas = new std::string[100];
	std::cout << "Copy constructor called for Brain" << std::endl;
	for (int i(0); i < 100; i++)
		this->ideas[i] = to_cpy.ideas[i];
}

Brain::~Brain()
{
	delete[] ideas;
	std::cout << "Destructor called for Brain" << std::endl;
}
