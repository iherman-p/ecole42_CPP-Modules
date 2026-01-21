/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:40:27 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/21 15:50:21 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	std::cout << "Init test" << std::endl;
	AForm* shrub_form = someRandomIntern.makeForm("shrubbery creation", "scene");;
	AForm* robo_form = someRandomIntern.makeForm("robotomy request", "Random guy #1");;
	AForm* pardon_form = someRandomIntern.makeForm("presidential pardon", "Random guy #2");;

	std::cout << "\nSign test" << std::endl;
	Bureaucrat	b1("Dave", 5);
	b1.signForm(*shrub_form);
	b1.signForm(*robo_form);
	b1.signForm(*pardon_form);

	std::cout << "\nExecution test" << std::endl;
	b1.executeForm(*shrub_form);
	b1.executeForm(*robo_form);
	b1.executeForm(*pardon_form);

	std::cout << "\nWrong form name test" << std::endl;
	AForm*	cool_form = someRandomIntern.makeForm("cool form", "Random cool guy #3");
	if (!cool_form)
	{
		std::cout << "cool from could not be executed as it's NULL" << std::endl;
	}
	else
	{
		b1.signForm(*cool_form);
		b1.executeForm(*cool_form);
	}
}
