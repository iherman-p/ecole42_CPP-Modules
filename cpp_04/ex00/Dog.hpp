/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:09:05 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/12 16:56:52 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal
{
	private:
	public:
		Dog();
		Dog(const Dog& to_cpy);
		virtual	~Dog();
		virtual void	makeSound() const;
};

#endif // DOG_HPP