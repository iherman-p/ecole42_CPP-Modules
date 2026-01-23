/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:13:19 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/23 18:57:28 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate();
void	identify(Base* ident);
void	identify(Base& ident);

int main()
{
	Base*	best_class_ever = generate();
	identify(best_class_ever);
	identify(*best_class_ever);
}
