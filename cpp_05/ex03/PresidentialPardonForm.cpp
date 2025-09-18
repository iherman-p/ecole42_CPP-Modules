/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:21:34 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/16 20:19:13 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: _AForm("PresidentialPardonForm", 145, 137), target("Default");
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: _AForm("PresidentialPardonForm", 145, 137), target(target);
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other);
	: _AForm(other), _target(other._target);
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	AForm::operator=(other);
	_target = other._target;
}

std::string	PresidentialPardonForm::getTarget()
{
	return _target;
}

void	PresidentialPardonForm::execute(const Bureaucrat& ex) const
{
	if (ex.getGrade() < _execReq)
	{
		throw AForm::GradeTooLowException();
		return ;
	}
	if (!_isSigned)
	{
		throw FormNotSignedException();
		return ;
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;		
}