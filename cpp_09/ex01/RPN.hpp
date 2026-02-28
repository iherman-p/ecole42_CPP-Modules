/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:53 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/25 21:04:32 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		enum Operator
		{
			MULT = '*',
			PLUS = '+',
			MINUS = '-',
			DIV = '/'
		};

		std::stack<int> c_;

		bool	isOperator(const char c) const;
		void	applyOperator(const Operator o);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int	evaluate(const std::string& expression);

		class InvalidCharacter : public std::exception
		{
			virtual const char* what() const throw();
		};
		class InsufficientElements : public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif // RPN_HPP
