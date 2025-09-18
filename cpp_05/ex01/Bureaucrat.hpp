/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 22:29:07 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/12 17:49:33 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <cstdint>
# include <ostream>

# define GRADE_MAX 1
# define GRADE_MIN 150

class Bureaucrat
{
	private:
		const std::string	_name;
		uint8_t				_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat() throw();

		Bureaucrat&	operator=(const Bureaucrat& other);

		std::uint8_t	getGrade() const;
		std::string		getName() const;

		//void			signForm();

		void		incrementGrade();
		void		decrementGrade();
		
		Bureaucrat&	operator++();
		Bureaucrat&	operator--();
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj);

#endif // BUREAUCRAT_HPP