/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:48:20 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/02 10:19:00 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define GRADE_MAX 150
# define GRADE_MIN 1

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& other);
		std::string	getName() const;
		int			getGrade() const;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP