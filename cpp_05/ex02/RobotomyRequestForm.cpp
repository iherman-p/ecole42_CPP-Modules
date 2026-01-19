/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:21:34 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/19 16:29:02 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::kGradeSign_ = 25;
const int RobotomyRequestForm::kGradeExec_ = 5;

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", kGradeSign_, kGradeExec_), target_("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", kGradeSign_, kGradeExec_), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target_(other.target_)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	AForm::operator=(other);
	target_ = other.target_;
}

std::string	RobotomyRequestForm::getTarget()
{
	return target_;
}

void		RobotomyRequestForm::executeAction(const Bureaucrat& b) const
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	if (std::rand() % 100 < 50)
		std::cout << _target << " has been robotomized." << std::endl;
	else
}