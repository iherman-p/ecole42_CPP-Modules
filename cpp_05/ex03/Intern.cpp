/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:58:17 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/21 15:44:30 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::~Intern()
{
}

static AForm*	createRobo(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	createPres(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

static AForm*	createShrub(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

Intern::Intern(const Intern& other)
{
	(void) other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void) other;
	return *this;
}

// Add any and all future form types to the create_form and types
AForm*	Intern::makeForm(const std::string& form_type, const std::string& target) const
{
	static const int	kFormAmount = 3;
	const std::string	types[kFormAmount] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm*				(*create_form[kFormAmount])(const std::string&) = {
		createRobo,
		createPres,
		createShrub
	};
	int		i = 0;

	while (i < kFormAmount)
	{
		if (form_type == types[i])
		{
			std::cout << "Intern creates " << form_type << std::endl;
			return create_form[i](target);
		}
		i++;
	}
	std::cout << "Intern couldn't create form because form name is unknown" << std::endl;
	return (NULL);
}
