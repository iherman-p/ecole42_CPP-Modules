/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:53:21 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 18:52:50 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: name_("Default_Form"), isSigned_(false), signReq_(GRADE_MIN), execReq_(GRADE_MIN)
{	
}

AForm::AForm(const std::string& name, const int signReq, const int execReq)
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

AForm::AForm(const AForm& other)
	: name_(other.name_), isSigned_(other.isSigned_), signReq_(other.signReq_), execReq_(other.execReq_)
{
}

AForm::~AForm() throw()
{
}

AForm&		AForm::operator=(const AForm& other)
{
	isSigned_ = other.isSigned_;
	return (*this);
}

const std::string&		AForm::getName() const
{
	return name_;
}

bool			AForm::getSigned() const
{
	return isSigned_;
}

std::uint8_t	AForm::getSignReq() const
{
	return signReq_;
}

std::uint8_t	AForm::getExecReq() const
{
	return execReq_;
}

void			AForm::beSigned(const Bureaucrat& b)
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

std::ostream&	operator<<(std::ostream& out, const AForm& f)
{
	out << f.getName() << " Form sign req: " << f.getSignReq()
		<< ", Form exec req: " << f.getExecReq()
		<< ", signed: " << std::boolalpha << f.getSigned() << std::noboolalpha;
	return out;
}
