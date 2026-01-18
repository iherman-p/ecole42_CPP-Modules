/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:19:27 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 18:40:57 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <cstdint>
# include <ostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string		name_;
		bool					isSigned_;
		const std::uint8_t		signReq_;
		const std::uint8_t		execReq_;
	public:
		Form();
		Form(const std::string& name, const int signReq, const int execReq);
		Form(const Form& other);
		~Form() throw();

		Form&	operator=(const Form& other);

		const std::string&		getName() const;
		bool					getSigned() const;
		std::uint8_t			getSignReq() const;
		std::uint8_t			getExecReq() const;

		void					beSigned(const Bureaucrat& b);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Form& obj);

#endif // FORM_HPP