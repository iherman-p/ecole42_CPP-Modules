/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:21:34 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/19 16:29:02 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const int ShrubberyCreationForm::kGradeSign_ = 145;
const int ShrubberyCreationForm::kGradeExec_ = 137;

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", kGradeSign_, kGradeExec_), target_("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", kGradeSign_, kGradeExec_), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target_(other.target_)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	target_ = other.target_;
}

std::string	ShrubberyCreationForm::getTarget()
{
	return target_;
}

void		ShrubberyCreationForm::executeAction(const Bureaucrat& b) const
{
	// make file

	file << "\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< "\n"
		<< "\n";
}