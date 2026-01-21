/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:38:27 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/21 15:12:13 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	std::cout << "Init test:" << std::endl;
	try {
		Form	f1("f1 (grade too high)", 0, 0);
		std::cout << "Form created: " << f1.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form	f2("f2 (grade too low)", 151, 151);
		std::cout << "Form created: " << f2.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nSign test:" << std::endl;
	try {
		Bureaucrat	b("John", 150);
		Form		f3("f3", 1, 1);
		b.signForm(f3);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nOperator = test: (Can only changes isSigned bool)" << std::endl;
	Form	f4("f4", 40, 60);
	f4.beSigned(Bureaucrat("Dan", 1));
	std::cout << f4 << std::endl;
	f4 = Form("f5", 50, 70);
	std::cout << f4 << std::endl;

	std::cout << "\nCopy constructor test:" << std::endl;
	std::cout << Form(f4) << std::endl;
}
