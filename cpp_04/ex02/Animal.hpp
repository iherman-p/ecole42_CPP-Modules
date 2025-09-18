/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:03:51 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/16 15:15:35 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(std::string new_type);
		Animal(Animal& to_cpy);
		virtual	~Animal();
		virtual void	makeSound() const = 0;
};

#endif // ANIMAL_HPP