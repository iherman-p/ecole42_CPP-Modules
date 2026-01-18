/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 22:29:07 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 18:51:34 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"

# include <string>
# include <cstdint>
# include <ostream>

# define GRADE_MAX 1
# define GRADE_MIN 150

class Bureaucrat
{
	private:
		const std::string	name_;
		uint8_t				grade_;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat() throw();

		Bureaucrat&	operator=(const Bureaucrat& other);

		std::uint8_t	getGrade() const;
		std::string		getName() const;

		void			incrementGrade();
		void			decrementGrade();

		void			signForm(AForm& f);
		void			executeForm(const AForm& form);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj);

#endif // BUREAUCRAT_HPP
