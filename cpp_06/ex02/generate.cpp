/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:16:06 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/23 18:53:20 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base*	generate()
{
	static bool	srand_called = false;
	if (srand_called == false)
	{
		std::srand(static_cast<unsigned int>(std::time(0)));
		srand_called = true;	
	}

	int	num = std::rand() % 300;

	if (num < 100)
		return new A;
	else if (num < 200)
		return new B;
	return new C;
}
