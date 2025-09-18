/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:20:02 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/16 15:38:34 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: _AForm("ShrubberyCreationForm", 145, 137), target("Default");
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: _AForm("ShrubberyCreationForm", 145, 137), target(target);
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other);
	: _AForm(other), _target(other._target);
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	_target = other._target;
}

std::string	ShrubberyCreationForm::getTarget()
{
	return _target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& ex) const
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
	std::ostream	file(target + "_Shrubbery");
	file << "       _-_";
	file << "    /~~   ~~\\";
	file << " /~~         ~~\\";
	file << "{               }";
	file << " \  _-     -_  /";
	file << "   ~  \\\\ //  ~";
	file << "_- -   | | _- _";
	file << "  _ -  | |   -_";
	file << "      // \\\\";
	file.close();
}