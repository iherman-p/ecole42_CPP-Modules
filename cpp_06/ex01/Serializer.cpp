/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:46:02 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/18 17:44:13 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static uintptr_t	Serializer::serialize(Data* ptr)
{
	return (static_cast<uintptr_t>(raw));
}

static Data* 		Serializer::deserialize(uintptr_t raw)
{
	return (static_cast<Data*>(raw));
}
