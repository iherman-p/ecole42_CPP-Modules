/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 22:47:17 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/13 12:24:04 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaurcrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
	: _name("Joey"), _grade(GRADE_MIN)
{
	
}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
	: _name(name), _grade(grade)
{
	if (_grade < GRADE_MAX || _grade > GRADE_MIN)
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{
	
}

Bureaucrat::~Bureaucrat() throw();
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other._grade;
	return *this;
}

std::uint8_t	Bureaucrat::getGrade() const
{
	return _grade;
}

std::string		Bureaucrat::getName() const
{
	return _name;
}

void		Bureaucrat::incrementGrade()
{
	if (_grade < GRADE_MIN)
		_grade++;
	else
		throw GradeTooLowException;
}

void		Bureaucrat::decrementGrade()
{
	if (_grade > GRADE_MAX)
		_grade--;
	else
		throw GradeTooHighException;
}

Bureaucrat&	Bureaucrat::operator++()
{
	if (_grade < GRADE_MIN)
		_grade++;
	else
		throw GradeTooLowException;
	return *this;
}

Bureaucrat&	Bureaucrat::operator--()
{
	if (_grade > GRADE_MAX)
		_grade--;
	else
		throw GradeTooHighException;
	return *this;
}

virtual const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	std::string	msg = "Bureaucrat grade too high (limits: " + GRADE_MAX + " - " + GRADE_MIN + ')';
	return (msg.c_str());
}

virtual const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	std::string	msg = "Bureaucrat grade too low (limits: " + GRADE_MAX + " - " + GRADE_MIN + ')';
	return (msg.c_str());
}
