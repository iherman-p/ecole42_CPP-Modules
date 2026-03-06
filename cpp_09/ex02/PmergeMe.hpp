/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:57 by iherman-          #+#    #+#             */
/*   Updated: 2026/03/06 22:04:59 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <cstddef>

class PmergeMe
{
	private:
		template <typename C>
		class Pair
		{
			public:
				Pair();
				Pair(int a, int b);
				Pair(const Pair& a, const Pair& b);
				~Pair();

				Pair&	operator=(const Pair& other);
				bool	operator<(const Pair& other) const;
				bool	operator>(const Pair& other) const;

				Pair		getLarge() const;
				Pair		getSmall() const;

				C			pair;
				std::size_t	pairSize;
		};

		PmergeMe();

		static std::vector<unsigned int>	getJacobsthal_(unsigned int max);

		template <typename C, typename T>
		static void	BinaryInsert_(C& container, T value);

		static void	sortVectorPair_(std::vector<Pair<std::vector<int> > >& data);
		static void	sortDequePair_(std::deque<Pair<std::deque<int> > >& data);

	public:
		PmergeMe(const PmergeMe& other);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe& other);

		static void	sortVector(std::vector<int>& data);
		static void	sortDeque(std::deque<int>& data);
};

template <typename C>
PmergeMe::Pair<C>::Pair()
	: pair(), pairSize(0)
{}

template <typename C>
PmergeMe::Pair<C>::Pair(int a, int b)
	: pair(), pairSize(1)
{
	if (a < b)
	{
		pair.push_back(b);
		pair.push_back(a);
	}
	else
	{
		pair.push_back(a);
		pair.push_back(b);
	}
}

template <typename C>
PmergeMe::Pair<C>::Pair(const Pair& a, const Pair& b)
	: pair(), pairSize(a.pairSize * 2)
{
	if (a < b)
	{
		this->pair.insert(pair.end(), b.pair.begin(), b.pair.end());
		this->pair.insert(pair.end(), a.pair.begin(), a.pair.end());
	}
	else
	{
		this->pair.insert(pair.end(), a.pair.begin(), a.pair.end());
		this->pair.insert(pair.end(), b.pair.begin(), b.pair.end());
	}
}

template <typename C>
PmergeMe::Pair<C>::~Pair()
{}

template <typename C>
PmergeMe::Pair<C>&	PmergeMe::Pair<C>::operator=(const Pair<C>& other)
{
	if (this != &other)
	{
		pair = other.pair;
		pairSize = other.pairSize;
	}
	return *this;
}

template <typename C>
bool	PmergeMe::Pair<C>::operator<(const PmergeMe::Pair<C>& other) const
{
	return pair[0] < other.pair[0];
}

template <typename C>
bool	PmergeMe::Pair<C>::operator>(const PmergeMe::Pair<C>& other) const
{
	return pair[0] > other.pair[0];
}

template <typename C>
PmergeMe::Pair<C>	PmergeMe::Pair<C>::getLarge() const
{
	Pair<C>	res = Pair<C>();

	res.pair.insert(res.pair.end(), pair.begin(), pair.begin() + pairSize);
	res.pairSize = pairSize / 2;

	return res;
}

template <typename C>
PmergeMe::Pair<C>	PmergeMe::Pair<C>::getSmall() const
{
	Pair<C>	res = Pair<C>();

	res.pair.insert(res.pair.end(), pair.begin() + pairSize, pair.begin() + pairSize * 2);
	res.pairSize = pairSize / 2;

	return res;
}

template <typename C, typename T>
void	PmergeMe::BinaryInsert_(C& container, T value)
{
	typename C::iterator pos =
			std::lower_bound(container.begin(), container.end(), value);
	container.insert(pos, value);
}

#endif // PMERGEME_HPP
