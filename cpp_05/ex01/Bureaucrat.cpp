/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 22:47:17 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 18:46:59 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
	: name_("Default Joey"), grade_(GRADE_MIN)
{
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade)
	: name_(name), grade_(grade)
{
	if (grade_ < GRADE_MAX)
		throw GradeTooHighException();
	else if (grade_ > GRADE_MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name_(other.name_), grade_(other.grade_)
{
}

Bureaucrat::~Bureaucrat() throw()
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade_ = other.grade_;
	return *this;
}

std::uint8_t	Bureaucrat::getGrade() const
{
	return grade_;
}

std::string		Bureaucrat::getName() const
{
	return name_;
}

void		Bureaucrat::incrementGrade()
{
	if (grade_ >= GRADE_MIN)
		throw GradeTooLowException();
	grade_++;
}

void		Bureaucrat::decrementGrade()
{
	if (grade_ >= GRADE_MAX)
		throw GradeTooHighException();
	grade_--;
}

void		Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << name_ << " signed " << f.getName();
	}
	catch (const std::exception& e)
	{
		std::cout << "Bureaucrat couldn't sign " << f.getName() << " because: " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	std::string	msg = "Bureaucrat grade too high (limits: " + std::to_string(GRADE_MAX) + " - " + std::to_string(GRADE_MIN) + ')';
	return (msg.c_str());
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	std::string	msg = "Bureaucrat grade too low (limits: " + std::to_string(GRADE_MAX) + " - " + std::to_string(GRADE_MIN) + ')';
	return (msg.c_str());
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << "Bureaucrat grade: " << obj.getGrade();
	return out;
}