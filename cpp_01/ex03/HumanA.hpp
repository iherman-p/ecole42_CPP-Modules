/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:58:29 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 16:14:39 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA(const std::string &name, Weapon &weapon);
		void	setWeapon(Weapon &new_weapon);
		void	attack() const;
};

#endif // HUMANA_HPP
