/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:42 by iherman-          #+#    #+#             */
/*   Updated: 2026/03/07 16:27:07 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <ctime>
#include <vector>
#include <deque>
#include <sys/time.h>

std::ostream&	operator<<(std::ostream& out, std::vector<int> obj)
{
	for (std::size_t i = 0; i < obj.size(); ++i)
	{
		std::cout << obj[i] << ' ';
	}
	return out;
}

std::ostream&	operator<<(std::ostream& out, std::deque<int> obj)
{
	for (std::size_t i = 0; i < obj.size(); ++i)
	{
		std::cout << obj[i] << ' ';
	}
	return out;
}

long long	get_time_us()
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL) != 0)
	{
		std::cerr << "Error: gettimeofday() failed" << std::endl;
		return 0;
	}

	return static_cast<long long>(tv.tv_sec) * 1000000LL + tv.tv_usec;
}

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: missing input" << std::endl;
		return 1;
	}

	std::vector<int>	data_vector;
	std::deque<int>		data_deque;

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

		data_vector.push_back(value);
		data_deque.push_back(value);
	}

	std::cout << "Before: " << data_vector << std::endl;

	long long	begin_vec = get_time_us();
	PmergeMe::sortVector(data_vector);
	long long	end_vec = get_time_us();

	long long	begin_deq = get_time_us(); 
	PmergeMe::sortDeque(data_deque);
	long long	end_deq = get_time_us();

	std::cout << "After: " << data_vector << std::endl;

	std::cout << "Time to process a range of " << data_vector.size() << " elements using std::vector<int> : " << end_vec - begin_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << data_deque.size() << " elements using std::deque<int> : " << end_deq - begin_deq << " us" << std::endl;

	return 0;
}
