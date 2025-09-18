/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:48:41 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/13 16:16:03 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string string("HI THIS IS BRAIN");
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << &string << '\n'
				<< stringPTR << '\n'
				<< &stringREF << std::endl;
	
	std::cout << string << '\n'
				<< *stringPTR << '\n'
				<< stringREF <<std::endl;
}
