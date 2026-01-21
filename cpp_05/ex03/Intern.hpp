/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:58:19 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/21 15:40:39 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(const std::string& form_type, const std::string& target) const;
};

#endif // INTERN_HPP