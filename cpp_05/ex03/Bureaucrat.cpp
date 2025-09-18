/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 22:47:17 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/16 15:31:10 by iherman-         ###   ########.fr       */
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
	if (_grade < GRADE_MAX)
		throw GradeTooLowException();
	if (_grade > GRADE_MIN)
		throw GradeTooHighException();
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

void	Bureaucrat::signForm(const AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " has signed " << f.getName() << std::endl;	
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " could not sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& f)
{
	try
	{
		f.execute(*this);
		std::cout << _name << " has signed " << f.getName() << std::endl;	
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " could not sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void		Bureaucrat::incrementGrade()
{
	if (_grade < GRADE_MIN)
		_grade--;
	else
		throw Bureaucrat::GradeTooLowException();
}

void		Bureaucrat::decrementGrade()
{
	if (_grade > GRADE_MAX)
		_grade++;
	else
		throw Bureaucrat::GradeTooHighException();
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

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj)
{
	std::cout << _name << " has grade " << _grade;
	return out;
}