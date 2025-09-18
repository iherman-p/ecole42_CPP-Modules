/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:05:51 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/12 16:26:26 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		Cat();
		Cat(const Cat& to_cpy);
		virtual	~Cat();
		virtual void	makeSound() const;
};

#endif // CAT_HPP