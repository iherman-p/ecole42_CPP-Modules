/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:39:39 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/16 15:01:01 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(PresidentialPardonForm& other);

		std::string	getTarget();

		void	execute(const Bureaucrat& ex) const;
}

#endif //PRESIDENTIALPARDONFORM_HPP