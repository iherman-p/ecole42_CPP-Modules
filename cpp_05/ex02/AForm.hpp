/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:19:27 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/20 21:58:34 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string		name_;
		bool					isSigned_;
		const int				signReq_;
		const int				execReq_;
	protected:
		virtual void			executeAction() const = 0;
	public:
		AForm();
		AForm(const std::string& name, const int signReq, const int execReq);
		AForm(const AForm& other);
		~AForm() throw();

		AForm&	operator=(const AForm& other);

		const std::string&		getName() const;
		bool					getSigned() const;
		int						getSignReq() const;
		int						getExecReq() const;

		void					beSigned(const Bureaucrat& b);
		void					execute(const Bureaucrat& b) const;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& obj);

#endif // FORM_HPP