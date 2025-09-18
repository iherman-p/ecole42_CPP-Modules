/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:13:58 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/05 17:11:27 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	get_replaced_text(std::ifstream &file, const std::string &replacee, const std::string &replacement)
{
	std::string		buffer;
	std::string		ret;
	size_t			i(0);

	buffer = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	if (replacee.empty())
		return buffer;
	while(i < buffer.size())
	{
		if (replacee.compare(buffer.substr(i, replacee.size())) == 0)
		{
			ret += replacement;
			i += replacee.size();
		}
		else
		{
			ret += buffer[i];
			i++;
		}
	}
	return ret;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Incorrect amount of arguments" << std::endl;
		return 1;
	}
	std::ifstream	file(argv[1]);
	if (!file)
	{
		std::cout << "Failed to open input file" << std::endl;
		return 2;
	}
	std::ofstream	new_file((std::string(argv[1]) + ".replace").c_str());
	if (!new_file)
	{
		file.close();
		std::cout << "Failed to create output file" << std::endl;
		return 2;
	}
	new_file << get_replaced_text(file, argv[2], argv[3]);
	file.close();
	new_file.close();
}
