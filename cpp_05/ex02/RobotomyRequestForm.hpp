/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:39:36 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 17:48:50 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(RobotomyRequestForm& other);

		std::string	getTarget();

		void	execute(const Bureaucrat& ex) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP