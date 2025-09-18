/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:58:17 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/18 13:00:03 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern()
{
	
}

~Intern()
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

AForm*	makeForm(std::string formType, std::string target) const
{
	const std::string	types[3] = {"robotomy request", "presidential pardon", "shrubbery creation"}
	AForm*		(createForm[3])(const std::string&) = {&createRobo, &createPres, &createShrub};
	int		i = 0;

	while (i < 4)
	{
		if (formType == types[i])
		{
			std::cout << "Intern created " << formType << std::endl;
			return createForm[i](target);
		}
		i++;
	}
	std::cout << "Form name does not exist -- Make sure name is spelled correctly and is in lower case" << std::endl;
	return (NULL);
}