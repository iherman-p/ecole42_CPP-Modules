/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:02:03 by iherman-          #+#    #+#             */
/*   Updated: 2026/03/06 22:18:22 by iherman-         ###   ########.fr       */
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

std::vector<unsigned int>	PmergeMe::getJacobsthal_(unsigned int max)
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

void	PmergeMe::sortVectorPair_(std::vector<Pair<std::vector<int> > >& data)
{
	if (data.size() <= 1)
		return ;

	std::vector<Pair<std::vector<int> > >	pairs;
	std::vector<Pair<std::vector<int> > >	main;
	std::vector<Pair<std::vector<int> > >	pend;

	pairs.reserve(data.size() / 2);
	for (std::size_t i = 0; i + 1 < data.size(); i += 2)
	{
		Pair<std::vector<int> >	pair(data[i], data[i + 1]);
		pairs.push_back(pair);
	}

	bool					has_straggler = (data.size() % 2 != 0);
	Pair<std::vector<int> >	straggler = Pair<std::vector<int> >();

	if (has_straggler)
		straggler = data.back();

	sortVectorPair_(pairs);

	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		main.push_back(pairs[i].getLarge());
		pend.push_back(pairs[i].getSmall());
	}

	BinaryInsert_(main, pend[0]);

	std::vector<unsigned int>	jacobs = getJacobsthal_(pend.size());

	for (std::size_t i = 2; i < jacobs.size(); ++i)
	{
		std::size_t	upper = jacobs[i];
		std::size_t	lower = jacobs[i - 1];

		if (upper > pend.size())
			upper = pend.size();

		for (; upper > lower; --upper)
			BinaryInsert_(main, pend[upper - 1]);
	}

	for (std::size_t i = pend.size() - 1; i > jacobs[jacobs.size() - 2] - 1; --i)
		BinaryInsert_(main, pend[i]);

	if (has_straggler)
		BinaryInsert_(main, straggler);

	data = main;
}

void	PmergeMe::sortVector(std::vector<int>& data)
{
	if (data.size() <= 1)
		return ;

	std::vector<Pair<std::vector<int> > >	pairs;
	std::vector<int>						main;
	std::vector<int>						pend;

	pairs.reserve(data.size() / 2);
	for (std::size_t i = 0; i + 1 < data.size(); i += 2)
	{
		Pair<std::vector<int> >	pair(data[i + 1], data[i]);
		pairs.push_back(pair);
	}

	bool	has_straggler = (data.size() % 2 != 0);
	int		straggler = 0;

	if (has_straggler)
		straggler = data.back();

	sortVectorPair_(pairs);

	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		main.push_back(pairs[i].pair[0]);
		pend.push_back(pairs[i].pair[pairs[i].pairSize]);
	}

	BinaryInsert_(main, pend[0]);

	std::vector<unsigned int>	jacobs = getJacobsthal_(pend.size());

	for (std::size_t i = 2; i < jacobs.size(); ++i)
	{
		std::size_t	upper = jacobs[i];
		std::size_t	lower = jacobs[i - 1];

		if (upper > pend.size())
			upper = pend.size();

		for (; upper > lower; --upper)
			BinaryInsert_(main, pend[upper - 1]);
	}

	for (std::size_t i = pend.size() - 1; i > jacobs[jacobs.size() - 2] - 1; --i)
		BinaryInsert_(main, pend[i]);

	if (has_straggler)
		BinaryInsert_(main, straggler);

	data = main;
}

void	PmergeMe::sortDequePair_(std::deque<Pair<std::deque<int> > >& data)
{
	if (data.size() <= 1)
		return ;

	std::deque<Pair<std::deque<int> > >	pairs;
	std::deque<Pair<std::deque<int> > >	main;
	std::deque<Pair<std::deque<int> > >	pend;

	for (std::size_t i = 0; i + 1 < data.size(); i += 2)
	{
		Pair<std::deque<int> >	pair(data[i], data[i + 1]);
		pairs.push_back(pair);
	}

	bool	has_straggler = (data.size() % 2 != 0);
	Pair<std::deque<int> >	straggler = Pair<std::deque<int> >();

	if (has_straggler)
		straggler = data.back();

	sortDequePair_(pairs);

	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		main.push_back(pairs[i].getLarge());
		pend.push_back(pairs[i].getSmall());
	}

	BinaryInsert_(main, pend[0]);

	std::vector<unsigned int>	jacobs = getJacobsthal_(pend.size());

	for (std::size_t i = 2; i < jacobs.size(); ++i)
	{
		std::size_t	upper = jacobs[i];
		std::size_t	lower = jacobs[i - 1];

		if (upper > pend.size())
			upper = pend.size();

		for (; upper > lower; --upper)
			BinaryInsert_(main, pend[upper - 1]);
	}

	for (std::size_t i = pend.size() - 1; i > jacobs[jacobs.size() - 2] - 1; --i)
		BinaryInsert_(main, pend[i]);

	if (has_straggler)
		BinaryInsert_(main, straggler);

	data = main;
}

void	PmergeMe::sortDeque(std::deque<int>& data)
{
	if (data.size() <= 1)
		return ;

	std::deque<Pair<std::deque<int> > >	pairs;
	std::deque<int>						main;
	std::deque<int>						pend;

	for (std::size_t i = 0; i + 1 < data.size(); i += 2)
	{
		Pair<std::deque<int> >	pair(data[i + 1], data[i]);
		pairs.push_back(pair);
	}

	bool	has_straggler = (data.size() % 2 != 0);
	int		straggler = 0;

	if (has_straggler)
		straggler = data.back();

	sortDequePair_(pairs);

	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		main.push_back(pairs[i].pair[0]);
		pend.push_back(pairs[i].pair[pairs[i].pairSize]);
	}

	BinaryInsert_(main, pend[0]);

	std::vector<unsigned int>	jacobs = getJacobsthal_(pend.size());

	for (std::size_t i = 2; i < jacobs.size(); ++i)
	{
		std::size_t	upper = jacobs[i];
		std::size_t	lower = jacobs[i - 1];

		if (upper > pend.size())
			upper = pend.size();

		for (; upper > lower; --upper)
			BinaryInsert_(main, pend[upper - 1]);
	}

	for (std::size_t i = pend.size() - 1; i > jacobs[jacobs.size() - 2] - 1; --i)
		BinaryInsert_(main, pend[i]);

	if (has_straggler)
		BinaryInsert_(main, straggler);

	data = main;
}
