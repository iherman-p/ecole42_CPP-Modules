/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:05:16 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/17 16:01:27 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int	main()
{
	std::size_t					mstack_size = 15;
	MutantStack<std::size_t>	mstack;

	for (std::size_t i = 0; i < mstack_size; ++i)
	{
		mstack.push(i);
	}

	for (MutantStack<std::size_t>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		*it = *it + 1;
	}

	const MutantStack<std::size_t>	kMStack(mstack);

	for (MutantStack<std::size_t>::const_reverse_iterator it = kMStack.rbegin(); it != kMStack.rend(); ++it)
	{
		std::cout << *it << std::endl;
	}
}
