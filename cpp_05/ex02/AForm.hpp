/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:19:27 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/16 20:16:12 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <cstdint>
# include <ostream>

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		std::uint8_t		signReq;
		std::uint8_t		execReq;
	public:
		AForm();
		AForm(const std::string& name, int sReq, int eReq);
		AForm(const AForm& other);
		~AForm();

		AForm&	operator=(const AForm& other);

		std::string		getName() const;
		bool			getSigned() const;

		void			beSigned(const Bureaucrat& b);
		void			execute(const Bureaucrat& ex) const = 0;

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
}

std::ostream&	operator<<(std::ostream& out, const AForm& obj);

#endif // AFORM_HPP