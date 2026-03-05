/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:02:03 by iherman-          #+#    #+#             */
/*   Updated: 2026/03/05 17:48:02 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void) other;
}

PmergeMe::~PmergeMe()
{}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	(void) other;
	return *this;
}

std::vector<unsigned int>	PmergeMe::getJacobsthal(unsigned int max)
{
	std::vector<unsigned int> jacobs;

	jacobs.push_back(0);
	jacobs.push_back(1);

	while (true)
	{
		unsigned int res = jacobs[jacobs.size() - 1] + (jacobs[jacobs.size() - 2] * 2);

		jacobs.push_back(res);
		if (res > max)
			break ;
	}

	return jacobs;
}
