/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:42 by iherman-          #+#    #+#             */
/*   Updated: 2026/03/01 19:55:14 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <limits>
#include <cerrno>

std::ostream&	operator<<(std::ostream& out, std::vector<int> obj)
{
	for (std::size_t i = 0; i < sorted.size(); ++i)
	{
		std::cout << sorted[i] << ' ';
	}
}

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: missing input" << std::endl;
		return 1;
	}

	std::vector<int>	data;

	for (int i = 1; i < argc; ++i)
	{
		char	*end;
		long	value;

		errno = 0;
		value = std::strtol(argv[i], &end, 10);

		if (*end != '\0' || errno == ERANGE || value > std::numeric_limits<int>::max()
			|| value < 0)
		{
			std::cerr << "Malformed input: " << argv[i] << std::endl;
			return 1;			
		}

		data.push_back(value);
	}

	std::cout << "Unsorted input: " << data << std::endl;

	std::vector<int>	sorted = PmergeMe::mergeSort(data);

	std::cout << "Sorted input: " << data << std::endl;

	return 0;
}