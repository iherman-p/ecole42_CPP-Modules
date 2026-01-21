/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 22:47:17 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/21 14:50:35 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
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

int	Bureaucrat::getGrade() const
{
	return grade_;
}

std::string		Bureaucrat::getName() const
{
	return name_;
}

void	Bureaucrat::incrementGrade()
{
	if (grade_ <= GRADE_MAX)
		throw GradeTooHighException();
	--grade_;
}

void	Bureaucrat::decrementGrade()
{
	if (grade_ >= GRADE_MIN)
		throw GradeTooLowException();
	++grade_;
}

void		Bureaucrat::signForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << name_ << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout <<  "Bureaucrat " << name_ << " couldn't sign " << f.getName() << " because: " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(const AForm& f)
{
	try
	{
		f.execute(*this);
		std::cout << name_ << " executed " << f.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Bureaucrat " << name_ << " couldn't execute " << f.getName() << " because: " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high (limits: 1 - 150)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low (limits: 1 - 150)";
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << " Bureaucrat grade: " << obj.getGrade();
	return out;
}
