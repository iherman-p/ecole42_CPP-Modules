/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:19:27 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 18:51:59 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <cstdint>
# include <ostream>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string		name_;
		bool					isSigned_;
		const std::uint8_t		signReq_;
		const std::uint8_t		execReq_;
	public:
		AForm();
		AForm(const std::string& name, const int signReq, const int execReq);
		AForm(const AForm& other);
		~AForm() throw();

		AForm&	operator=(const AForm& other);

		const std::string&		getName() const;
		bool					getSigned() const;
		std::uint8_t			getSignReq() const;
		std::uint8_t			getExecReq() const;

		void					beSigned(const Bureaucrat& b);
		virtual void			execute(const Bureaucrat& b) const = 0;

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

std::ostream&	operator<<(std::ostream& out, const AForm& obj);

#endif // FORM_HPP