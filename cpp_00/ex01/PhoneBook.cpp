/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:34:26 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/17 14:25:18 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>

static std::string pb_get_contact_field(std::string request_msg)
{
	std::string	user_input;

	while (1)
	{
		std::cout << request_msg << ' ';
		std::getline(std::cin, user_input);
		if (user_input == "")
			std::cout << "Cannot have empty field; Provide input" << std::endl;
		else
			break;
	}
	return user_input;
}

static int	pb_get_user_index(int max)
{
	int	user_input;

	while (1)
	{
		if (!(std::cin >> user_input))
		{
			std::cout << "Please provide a valid number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			if (user_input > 0 && user_input <= max)
				break;
			std::cout << "Number provided does not match a contact" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return user_input;
}

void	PhoneBook::add_contact()
{
	_contacts[_new_contact].setFirstName(pb_get_contact_field("First name:"));
	_contacts[_new_contact].setLastName(pb_get_contact_field("Last name:"));
	_contacts[_new_contact].setNickname(pb_get_contact_field("Nickname:"));
	_contacts[_new_contact].setPhoneNumber(pb_get_contact_field("Phone number:"));
	_contacts[_new_contact].setDarkestSecret(pb_get_contact_field("Darkest secret:"));
	_new_contact = (_new_contact + 1) % CONTACT_MAX;
	if (_contact_amount < CONTACT_MAX)
		_contact_amount++;
	std::cout << "Contact has been added" << std::endl;
}

void	PhoneBook::search_contact() const
{
	int	i;

	i = 0;
	if (_contact_amount < 1)
	{
		std::cout << "No contacts have been added" << std::endl;
		return ;
	}
	std::cout << "*Index     *Firstname *Lastname  *Nickname  *" << std::endl;
	while (i < _contact_amount)
	{
		std::cout << "o----------o----------o----------o----------o" << std::endl;
		std::cout << "|         " << (i + 1) << '|';
		_contacts[i].displayContactFields();
		i++;
	}
	std::cout << "o----------o----------o----------o----------o" << std::endl;
	i = pb_get_user_index(_contact_amount);
	std::cout << _contacts[i].getFirstName() << '\n'
				<< _contacts[i].getLastName() << '\n'
				<< _contacts[i].getNickname() << '\n'
				<< _contacts[i].getPhoneNumber() << std::endl;
}
