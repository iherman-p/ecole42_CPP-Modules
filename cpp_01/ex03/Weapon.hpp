/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:58:39 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 16:15:41 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon();
		Weapon(const std::string &type);
		const std::string	&getType() const;
		void				setType(const std::string &new_type);
};

#endif // WEAPON_HPP
