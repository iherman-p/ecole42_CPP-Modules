/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:55:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/16 15:14:48 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	public:
		std::string	*ideas;

		Brain();
		Brain(std::string new_idea);
		Brain(const Brain& to_cpy);
		~Brain();
};

#endif // BRAIN_HPP