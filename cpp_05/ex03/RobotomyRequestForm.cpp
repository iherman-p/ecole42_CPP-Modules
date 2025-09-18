/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:21:06 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/16 20:22:00 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: _AForm("RobotomyRequestForm", 145, 137), target("Default");
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: _AForm("RobotomyRequestForm", 145, 137), target(target);
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other);
	: _AForm(other), _target(other._target);
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm& other)
{
	AForm::operator=(other);
	_target = other._target;
}

std::string	RobotomyRequestForm::getTarget()
{
	return _target;
}

void	RobotomyRequestForm::execute(const Bureaucrat& ex) const
{
	if (ex.getGrade() < _execReq)
	{
		throw AForm::GradeTooLowException;
		return ;		
	}
	if (!_isSigned)
	{
		std::cout << _name << " cannot be executed as it isn't signed" << std::endl;
		return ;
	}
	std::srand(static_cast<unsigned int>(std::time(0)));
	if (std::rand() % 100 < 50)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		
}