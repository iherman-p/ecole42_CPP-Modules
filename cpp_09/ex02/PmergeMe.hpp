/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:57 by iherman-          #+#    #+#             */
/*   Updated: 2026/03/05 19:56:48 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
	private:
		template <typename T>
		class Pair
		{
			public:
				Pair();
				Pair(T a, T b);
				~Pair();

				Pair&	operator=(const Pair& other);
				bool	operator<(const Pair& other);
				bool	operator>(const Pair& other);

				T	larger;
				T	smaller;
		};

		PmergeMe();

		static std::vector<unsigned int>	getJacobsthal(unsigned int max);

		template <typename T>
		static void	BinaryInsertVector(std::vector<T>& container, T value);
		template <typename T>
		static void	BinaryInsertDeque(std::deque<T>& container, T value);

	public:
		PmergeMe(const PmergeMe& other);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe& other);

		template <typename T>
		static std::vector<T>	sortVector(std::vector<T>& data);
		template <typename T>
		static std::deque<T>	sortDeque(std::deque<T>& data);
};

template <typename T>
PmergeMe::Pair<T>::Pair()
	: larger(), smaller()
{}

template <typename T>
PmergeMe::Pair<T>::Pair(T a, T b)
{
	if (a < b)
	{
		larger = b;
		smaller = a;
	}
	else
	{
		larger = a;
		smaller = b;
	}
}

template <typename T>
PmergeMe::Pair<T>::~Pair()
{}

template <typename T>
PmergeMe::Pair<T>&	PmergeMe::Pair<T>::operator=(const Pair<T>& other)
{
	if (this != &other)
	{
		larger = other.larger;
		smaller = other.larger;
	}
	return *this;
}

template <typename T>
bool	PmergeMe::Pair<T>::operator<(const PmergeMe::Pair<T>& other)
{
	return larger < other.larger;
}

template <typename T>
bool	PmergeMe::Pair<T>::operator>(const PmergeMe::Pair<T>& other)
{
	return larger > other.larger;
}

template <typename T>
void	PmergeMe::BinaryInsertVector(std::vector<T>& container, T value)
{
	typename std::vector<T>::iterator pos =
			std::lower_bound(container.begin(), container.end(), value);
	container.insert(pos, value);
}

template <typename T>
std::vector<T>	PmergeMe::sortVector(std::vector<T>& data)
{
	if (data.size() <= 1)
		return data;

	std::vector<Pair<T> >	pend;
	std::vector<T>			main;

	pend.reserve(data.size() / 2);
	main.reserve(data.size());
	for (std::size_t i = 0; i + 1 < data.size(); i += 2)
		pend.push_back(Pair<T>(data[i + 1], data[i]));

	bool	has_straggler = (data.size() % 2 != 0);
	T		straggler = T();

	if (has_straggler)
		straggler = data.back();

	pend = sortVector(pend);

	for (std::size_t i = 0; i < pend.size(); ++i)
		main.push_back(pend[i].larger);
	
	BinaryInsertVector(main, pend[0].smaller);

	std::vector<unsigned int>	jacobs = getJacobsthal(pend.size());

	for (std::size_t i = 2; i < jacobs.size(); ++i)
	{
		std::size_t	upper = jacobs[i];
		std::size_t	lower = jacobs[i - 1];

		if (upper > pend.size())
			upper = pend.size();

		for (; upper > lower; --upper)
			BinaryInsertVector(main, pend[upper - 1].smaller);
	}

	for (std::size_t i = pend.size() - 1; i > jacobs[jacobs.size() - 2] - 1; --i)
		BinaryInsertVector(main, pend[i].smaller);

	if (has_straggler)
		BinaryInsertVector(main, straggler);

	data = main;
	return data;
}

#endif // PMERGEME_HPP
