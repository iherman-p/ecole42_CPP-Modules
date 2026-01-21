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
#include <iostream>
#include <fstream>

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
	return *this;
}

std::string	ShrubberyCreationForm::getTarget()
{
	return target_;
}

void		ShrubberyCreationForm::executeAction() const
{
	std::ofstream file;
	file.open((target_ + std::string("_shrubbery")).c_str());

	if (!file.is_open())
		std::cerr << "Could not create " << target_ + "_shrubbery" << std::endl;

	file << "       _-_\n"
		<< "    /~~   ~~\\\n"
		<< " /~~         ~~\\\n"
		<< "{               }\n"
		<< " \\  _-     -_  /\n"
		<< "   ~  \\\\ //  ~\n"
		<< "_- -   | | _- _\n"
		<< "  _ -  | |   -_\n"
		<< "      // \\\\\n";
}
