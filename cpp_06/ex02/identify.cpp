/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:16:10 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/23 18:59:14 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void	identify(Base* ident)
{
	std::cout << "Pointer-based identification\n";

	if (dynamic_cast<A*>(ident) != NULL)
		std::cout << "Object is type A" << std::endl;
	else if (dynamic_cast<B*>(ident) != NULL)
		std::cout << "Object is type B" << std::endl;
	else if (dynamic_cast<C*>(ident) != NULL)
		std::cout << "Object is type C" << std::endl;
	else
		std::cout << "Object is unidentified derived type" << std::endl;
}

void	identify(Base& ident)
{
	std::cout << "Reference-based identification\n";

	try
	{
		(void) dynamic_cast<A&>(ident);
		std::cout << "Object is type A" << std::endl;	
		return ;
	}
	catch (const std::exception& e) {}
	try
	{
		(void) dynamic_cast<B&>(ident);
		std::cout << "Object is type B" << std::endl;	
		return ;
	}
	catch (const std::exception& e) {}
	try
	{
		(void) dynamic_cast<C&>(ident);
		std::cout << "Object is type C" << std::endl;	
		return ;
	}
	catch (const std::exception& e) {}
	std::cout << "Object is unidentified derived type" << std::endl;
}
