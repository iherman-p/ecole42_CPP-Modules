/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:32:19 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/12 16:36:05 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(std::string const & type);
		[...];

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP