/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Icharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:55:24 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/16 14:56:57 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AMateria.hpp"

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif // ICHARACTER_HPP