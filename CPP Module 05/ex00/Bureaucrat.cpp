/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:48:18 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/02 10:22:15 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default Dave"), _grade(GRADE_MAX)
{
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
	: _name(name), _grade(grade)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << "Bureucrat grade " << b.getGrade();
	return out;
}