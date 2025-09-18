/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:12:51 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/04 18:12:11 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CONTACT_MAX 8

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact _contacts[CONTACT_MAX];
		int		_new_contact;
		int		_contact_amount;
	public:
				PhoneBook();
		void	add_contact(void);
		void	search_contact(void) const;
};

#endif //PHONEBOOK_HPP
