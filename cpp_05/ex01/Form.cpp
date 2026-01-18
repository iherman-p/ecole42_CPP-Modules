/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:53:21 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 18:46:37 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: name_("Default_Form"), isSigned_(false), signReq_(GRADE_MIN), execReq_(GRADE_MIN)
{	
}

Form::Form(const std::string& name, const int signReq, const int execReq)
	: name_(name), isSigned_(false), signReq_(signReq), execReq_(execReq)
{
	if (signReq < GRADE_MAX)
		throw GradeTooHighException();
	else if (signReq > GRADE_MIN)
		throw GradeTooLowException();
	if (execReq < GRADE_MAX)
		throw GradeTooHighException();
	else if (execReq > GRADE_MIN)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: name_(other.name_), isSigned_(other.isSigned_), signReq_(other.signReq_), execReq_(other.execReq_)
{
}

Form::~Form() throw()
{
}

Form&		Form::operator=(const Form& other)
{
	isSigned_ = other.isSigned_;
	return (*this);
}

const std::string&		Form::getName() const
{
	return name_;
}

bool			Form::getSigned() const
{
	return isSigned_;
}

std::uint8_t	Form::getSignReq() const
{
	return signReq_;
}

std::uint8_t	Form::getExecReq() const
{
	return execReq_;
}

void			Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > signReq_)
		throw GradeTooLowException();
	isSigned_ = true;		
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	std::string	msg = "Grade too high (limits: " + std::to_string(GRADE_MAX) + " - " + std::to_string(GRADE_MIN) + ')';
	return (msg.c_str());
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	std::string	msg = "Grade too low (limits: " + std::to_string(GRADE_MAX) + " - " + std::to_string(GRADE_MIN) + ')';
	return (msg.c_str());
}

std::ostream&	operator<<(std::ostream& out, const Form& f)
{
	out << f.getName() << " Form sign req: " << f.getSignReq()
		<< ", Form exec req: " << f.getExecReq()
		<< ", signed: " << std::boolalpha << f.getSigned() << std::noboolalpha;
	return out;
}
