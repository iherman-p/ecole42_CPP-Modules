/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:39:36 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/16 15:00:57 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
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
}

#endif // ROBOTOMYREQUESTFORM_HPP