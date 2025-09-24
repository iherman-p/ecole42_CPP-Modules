/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:01:58 by iherman-          #+#    #+#             */
/*   Updated: 2025/09/23 23:06:31 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data*	data = new Data;
	
	data->message = "Greetings from Data struct";	
	uintptr_t	dataAddr = Serializer::serialize(data);

	Data*	newData = deserialize(dataAddr);
	std::cout << data->message << std::endl;

	std::cout << "Comparison of pointers:\n" << "Data: " << data << "\nnewData: " << newData << std::endl;
	delete data;
}