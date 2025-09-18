/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:53:55 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/16 15:25:59 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	PresidentialPardonForm	pardonForm("Eliot");
	RobotomyRequestForm		roboForm("Eliot");
	ShrubberyCreationForm	shrubForm("shrub_file");

	Bureaucrat				Craig("Craig", GRADE_MAX);
	Bureaucrat				Liam("Liam", GRADE_MIN);

	Liam.execute(pardonForm);
	Craig.execute(pardonForm);
	Liam.signForm(pardonForm);
	Liam.executeForm(pardonForm);
	Craig.executeForm(pardonForm);

	Craig.signForm(roboForm);
	Craig.signForm(shrubForm);
	Craig.executeForm(roboForm);
	Craig.executeForm(shrubForm);
}
