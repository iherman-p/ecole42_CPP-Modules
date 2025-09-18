/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:01:21 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/05 15:58:55 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie rick("Rick Grimes");
	Zombie *daryl;

	daryl = newZombie("Daryl Dixon");
	
	daryl->announce();
	rick.announce();
	randomChump("Background extra");
	delete daryl;
}
