/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:21:34 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/19 16:29:02 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::kGradeSign_ = 25;
const int PresidentialPardonForm::kGradeExec_ = 5;

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", kGradeSign_, kGradeExec_), target_("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", kGradeSign_, kGradeExec_), target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target_(other.target_)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
	AForm::operator=(other);
	target_ = other.target_;
}

std::string	PresidentialPardonForm::getTarget()
{
	return target_;
}

void		PresidentialPardonForm::executeAction(const Bureaucrat& b) const
{
	
}