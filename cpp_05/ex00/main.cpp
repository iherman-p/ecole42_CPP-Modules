/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:38:27 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/21 15:11:06 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	std::cout << "Init test:" << std::endl;
	try
	{
		Bureaucrat	b1("b1 (grade too high)", 0);
		std::cout << "Bureaucrat created: " << b1.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b2("b2 (grade too low)", 151);
		std::cout << "Bureaucrat created: " << b2.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b3("b3", 150);
		std::cout << "Bureaucrat created: " << b3.getName() << std::endl;
		b3.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nIncrement/decrement test:" << std::endl;
	Bureaucrat b4("Daniel", 100);
	std::cout << b4 << std::endl;
	b4.decrementGrade();
	std::cout << b4 << std::endl;
	b4.incrementGrade();
	std::cout << b4 << '\n' << "\nOperator = test:" << std::endl;
	b4 = Bureaucrat("Horace", 50);
	std::cout << b4 << std::endl;
}

