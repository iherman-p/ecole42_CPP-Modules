/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:27:28 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 15:12:57 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &to_cpy);
		virtual	~ScavTrap();

		ScavTrap&		operator=(const ScavTrap& to_cpy);

		virtual void	attack(const std::string &target);
		void			guardGate();
};

#endif // SCAVTRAP_HPP