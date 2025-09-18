/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:53:21 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/13 13:17:33 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("Default_Form"), _isSigned(false), signReq(GRADE_MAX), execReq(GRADE_MAX)
{	
}

AForm::AForm(const std::string& name, int signReq, int execReq);
	: _name(name), _isSigned(false), _signReq(signReq), _execReq(execReq)
{
}

AForm::AForm(const AForm& other);
	: _name(other.name), _isSigned(other._isSigned), _signReq(other._signReq), _execReq(other._execReq)
{
}

AForm::~AForm()
{
}

AForm&		AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		_signReq = other._signReq;
		_execReq = other._execReq;
	}
	return (*this);
}

std::string		AForm::getName() const
{
	return _name;
}

bool			AForm::getSigned() const
{
	return _isSigned;
}

std::uint8_t	AForm::getSignReq() const
{
	return _signReq;
}

std::uint8_t	AForm::getExecReq() const
{
	return _execReq;
}

void			AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() >= _signReq)
		_isSigned = true;
	else
		throw GradeTooLowException;
}

virtual const char* AForm::GradeTooHighException::what() const throw()
{
	std::string	msg = "Bureaucrat grade too high (limits: " + GRADE_MAX + " - " + GRADE_MIN + ')';
	return (msg.c_str());
}

virtual const char* AForm::GradeTooLowException::what() const throw()
{
	std::string	msg = "Bureaucrat grade too low (limits: " + GRADE_MAX + " - " + GRADE_MIN + ')';
	return (msg.c_str());
}

virtual const char* FormNotSignedException::what() const throw()
{
	std::string	msg = "Form has to be signed before execution";
	return (msg.c_str());
}