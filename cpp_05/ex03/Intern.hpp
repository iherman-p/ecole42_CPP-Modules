/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:58:19 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/17 20:03:28 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define Intern_HPP

# include "AForm.hpp"

class	Intern : public AForm
{
	public:
		Intern();
		~Intern();

		AForm*	makeForm(std::string formType, std::string target) const;
}

#endif // Intern_HPP