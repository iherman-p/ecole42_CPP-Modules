/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:51 by iherman-          #+#    #+#             */
/*   Updated: 2026/03/07 15:22:28 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

bool	RPN::isOperator(const char c) const
{
	if (c == '*'
		|| c == '+'
		|| c == '-'
		|| c == '/')
		return true;
	return false;
}

void	RPN::applyOperator(const RPN::Operator op)
{
	if (c_.size() < 2)
		throw InsufficientElements();

	int	n1 = c_.top();
	c_.pop();

	int	n2 = c_.top();
	c_.pop();

	int	res;
	if (op == PLUS)
		res = n2 + n1;
	else if (op == MINUS)
		res = n2 - n1;
	else if (op == MULT)
		res = n2 * n1;
	else if (op == DIV)
	{
		if (n1 == 0)
			throw DivisionByZero();
		res = n2 / n1;
	}

	c_.push(res);
}

RPN::RPN()
	: c_()
{}

RPN::RPN(const RPN& other)
	: c_(other.c_)
{}

RPN::~RPN()
{}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->c_ = other.c_;
	}
	return *this;
}

int	RPN::evaluate(const std::string& expression)
{
	c_ = std::stack<int>();
	
	for (std::size_t i = 0; i < expression.size(); ++i)
	{
		if (expression[i] == ' ')
			continue ;

		if (isdigit(expression[i]))
			c_.push(static_cast<int>(expression[i] - '0'));
		else if (isOperator(expression[i]))
			applyOperator(static_cast<Operator>(expression[i]));
		else
			throw InvalidCharacter();
	}

	if (c_.size() != 1)
		throw ElementOperatorMismatch();

	return c_.top();
}

const char* RPN::InvalidCharacter::what() const throw()
{
	return "Invalid character";
}

const char* RPN::InsufficientElements::what() const throw()
{
	return "Not enough elements to apply operator";
}

const char* RPN::ElementOperatorMismatch::what() const throw()
{
	return "Operator/operand mismatch";
}

const char* RPN::DivisionByZero::what() const throw()
{
	return "Division by zero not allowed";
}
