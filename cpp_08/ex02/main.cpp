/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:05:16 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/18 16:02:12 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int	main()
{
	std::size_t					mstack_size = 15;
	MutantStack<std::size_t>	mstack;

	for (std::size_t i = 0; i < mstack_size; ++i)
	{
		mstack.push(i);
	}

	std::cout << "Before iteration: " << std::endl;
	for (MutantStack<std::size_t>::const_reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;

	for (MutantStack<std::size_t>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		*it = *it + 100;
	}

	const MutantStack<std::size_t>	kmstack(mstack);

	std::cout << "After iteration: " << std::endl;
	for (MutantStack<std::size_t>::const_reverse_iterator it = kmstack.rbegin(); it != kmstack.rend(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}
