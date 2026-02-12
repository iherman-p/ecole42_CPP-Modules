/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:05:16 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/11 15:15:24 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <iterator>

int	main()
{
	std::vector<int>	v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::vector<int>::iterator	found = easyfind(v, 3);
	std::vector<int>::iterator 	not_found = easyfind(v, 10);

	std::cout << "found: " << *found << std::endl;
	std::cout << "not_found: " << *not_found << std::endl;
}
