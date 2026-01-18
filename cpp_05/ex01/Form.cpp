/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:53:21 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 17:51:43 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("Default_Form"), _isSigned(false), _signReq(GRADE_MAX), _execReq(GRADE_MAX)
{	
}

Form::Form(const std::string name, const int signReq, const int execReq)
	: _name(name), _isSigned(false), _signReq(signReq), _execReq(execReq)
{
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _signReq(other._signReq), _execReq(other._execReq)
{
}

Form::~Form()
{
}

Form&		Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		_signReq = other._signReq;
		_execReq = other._execReq;
	}
	return (*this);
}

std::string		Form::getName() const
{
	return _name;
}

bool			Form::getSigned() const
{
	return _isSigned;
}

std::uint8_t	Form::getSignReq() const
{
	return _signReq;
}

std::uint8_t	Form::getExecReq() const
{
	return _execReq;
}

void			Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() >= _signReq)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

virtual const char* Form::GradeTooHighException::what() const throw()
{
	std::string	msg = "Bureaucrat grade too high (limits: " + GRADE_MAX + " - " + GRADE_MIN + ')';
	return (msg.c_str());
}

virtual const char* Form::GradeTooLowException::what() const throw()
{
	std::string	msg = "Bureaucrat grade too low (limits: " + GRADE_MAX + " - " + GRADE_MIN + ')';
	return (msg.c_str());
}
