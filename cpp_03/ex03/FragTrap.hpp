/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:14:32 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 15:13:02 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &to_cpy);
		virtual	~FragTrap();

		FragTrap&		operator=(const FragTrap& to_cpy);
		
		virtual void	attack(const std::string &target);
		void			highFivesGuys();
};

#endif // FRAGTRAP_HPP
