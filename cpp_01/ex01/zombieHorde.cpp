/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:47:23 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/05 16:02:40 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde;

	if (N < 1)
		return NULL;
	horde = new Zombie[N];
	for (int i(0); i < N; i++)
		horde[i].setName(name);
	return horde;
}
