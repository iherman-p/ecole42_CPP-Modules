/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:18:54 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 16:08:03 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &to_cpy);
		virtual	~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap& to_cpy);

		using	ClapTrap::attack;
		void	whoAmI();
};

#endif // DIAMONDTRAP_HPP