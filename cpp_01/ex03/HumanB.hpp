/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:58:33 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 16:14:06 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon		*_weapon;

	public:
		HumanB(const std::string &name);
		void	setWeapon(Weapon &new_weapon);
		void	attack() const;
};

#endif // HUMANB_HPP
