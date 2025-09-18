/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:18:44 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/31 15:27:09 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <string>

class	Contact
{
	private:
		std::string	_darkest_secret;
		std::string	_first_name;
		std::string _last_name;
		std::string	_nickname;
		std::string _phone_number;
	public:
		void	displayContactFields() const;

		/* setters */
		void	setDarkestSecret(std::string input);
		void	setFirstName(std::string input);
		void	setLastName(std::string input);
		void	setNickname(std::string input);
		void	setPhoneNumber(std::string input);

		/* getters */
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
};

#endif //CONTACTS_HPP
