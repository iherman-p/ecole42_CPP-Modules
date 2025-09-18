/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:39:45 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/14 13:23:10 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(ShrubberyCreationForm& other);

		std::string	getTarget();

		void	execute(const Bureaucrat& ex) const;
}

#endif // SHRUBBERYCREATIONFORM_HPP