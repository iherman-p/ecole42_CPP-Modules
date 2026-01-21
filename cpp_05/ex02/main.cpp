/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:40:27 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/21 15:30:12 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	ShrubberyCreationForm	shrub_form("Beautiful");
	RobotomyRequestForm		robo_form("John Davis");
	PresidentialPardonForm	pardon_form("Davis Johns");

	Bureaucrat				b1("Beautiful Bart", 1);
	Bureaucrat				b2("Bad Bart", 150);

	std::cout << "Sign form failure test:" << std::endl;
	try
	{
		b2.signForm(shrub_form);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\nExecute form success test:" << std::endl;
	try
	{
		b1.signForm(shrub_form);
		b1.executeForm(shrub_form);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << '\n';
	b1.signForm(robo_form);
	b1.signForm(pardon_form);

	std::cout << "\nExecute form failure test:" << std::endl;
	b2.executeForm(pardon_form);

	std::cout << "\nExecute forms tests:" << std::endl;
	b1.executeForm(robo_form);
	b1.executeForm(pardon_form);
}
