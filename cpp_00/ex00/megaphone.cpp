/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:23 by iherman-          #+#    #+#             */
/*   Updated: 2025/06/19 13:08:24 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (j < argc)
		{
			i = 0;
			while (argv[j][i])
			{
				std::cout.put(toupper(static_cast<unsigned char>(argv[j][i])));
				i++;
			}
			j++;
		}
		std::cout << std::endl;
	}
}
