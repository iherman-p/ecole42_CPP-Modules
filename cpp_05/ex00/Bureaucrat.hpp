/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 22:29:07 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/21 14:20:14 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <ostream>

# define GRADE_MAX 1
# define GRADE_MIN 150

class AForm;

class Bureaucrat
{
	private:
		const std::string	name_;
		int					grade_;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat() throw();

		Bureaucrat&	operator=(const Bureaucrat& other);

		int				getGrade() const;
		std::string		getName() const;

		void			incrementGrade();
		void			decrementGrade();

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
