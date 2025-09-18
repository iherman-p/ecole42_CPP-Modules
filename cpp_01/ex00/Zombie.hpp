/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:32:21 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 16:16:18 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(const std::string &name);
		Zombie();
		~Zombie();
		void	announce();
		void	setName(const std::string &new_name);
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif // ZOMBIE_HPP
