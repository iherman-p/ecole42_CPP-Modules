/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:14:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/04 18:11:52 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	Phonebook;
	std::string	user_input;

	std::cout << "* Welcome to the AwesomePhonebook! *" << std::endl;
	while (1)
	{
		std::cout << "Options: 'ADD' a contact, 'SEARCH' for a contact, and 'EXIT'" << std::endl;
		if (!std::getline(std::cin, user_input))
			break ;
		if (user_input == "EXIT")
			break ;
		else if (user_input == "ADD")
			Phonebook.add_contact();
		else if (user_input == "SEARCH")
			Phonebook.search_contact();
		else
			std::cout << "Not a valid option: \'" << user_input << "\'\n";
	}
}