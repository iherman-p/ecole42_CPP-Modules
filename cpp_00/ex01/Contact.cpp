/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:21:55 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/31 15:27:52 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Contact.hpp"
#include <iostream>
#include <string>

static inline void	display_single_field(std::string field)
{
	std::string	whitespace;
	std::string	field_display;

	if (field.size() >= 10)
		field_display = field.substr(0, 9) + ".";
	else
	{
		while ((whitespace.size() + field.size()) < 10)
			whitespace = whitespace + " ";
		field_display = whitespace + field;
	}
	std::cout << field_display << "|";
}

void	Contact::displayContactFields() const
{
	display_single_field(_first_name);
	display_single_field(_last_name);
	display_single_field(_nickname);
	std::cout << std::endl;
}

/* setters */

void	Contact::setDarkestSecret(std::string input)
{
	_darkest_secret = input;
}

void	Contact::setFirstName(std::string input)
{
	_first_name = input;
}

void	Contact::setLastName(std::string input)
{
	_last_name = input;
}

void	Contact::setNickname(std::string input)
{
	_nickname = input;
}

void	Contact::setPhoneNumber(std::string input)
{
	_phone_number = input;
}

/* getters */

std::string	Contact::getFirstName() const
{
	return _first_name;
}

std::string	Contact::getLastName() const
{
	return _last_name;
}

std::string	Contact::getNickname() const
{
	return _nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return _phone_number;
}
