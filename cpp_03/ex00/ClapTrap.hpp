/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:44:53 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 14:55:08 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string name;
		int	hp;
		int	ep;
		int	atk_dmg;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &to_cpy);
		~ClapTrap();
	
		ClapTrap&	operator=(const ClapTrap& to_cpy);
		
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP