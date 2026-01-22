/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:41:41 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/22 18:23:36 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	public:
		virtual ~ScalarConverter() = 0;
		static void	convert(const std::string& data);
};

#endif // SCALARCONVERTER_HPP