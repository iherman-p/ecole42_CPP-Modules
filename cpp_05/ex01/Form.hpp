/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:19:27 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/21 15:09:25 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string		name_;
		bool					isSigned_;
		const int				signReq_;
		const int				execReq_;
	public:
		Form();
		Form(const std::string& name, const int signReq, const int execReq);
		Form(const Form& other);
		~Form() throw();

		Form&	operator=(const Form& other);

		const std::string&		getName() const;
		bool					getSigned() const;
		int						getSignReq() const;
		int						getExecReq() const;

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
