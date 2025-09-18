/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:58:24 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/16 15:11:29 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* a1 = new Dog();
	const Animal* a2 = new Cat();
	delete a1;//should not create a leak
	delete a2;

	{
		Animal* herd[100];
		for (int i(0); i < 100; i++)
		{
			if (i % 2 == 0)
				herd[i] = new Dog();
			else
				herd[i] = new Cat();
		}
		for (int i(0); i < 100; i++)
			herd[i]->makeSound();
		for (int i(0); i < 100; i++)
			delete herd[i];
	}
	return (0);
}
