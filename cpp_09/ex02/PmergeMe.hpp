/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:57 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/27 16:04:32 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);

	public:
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		static std::vector<int>	mergeSort(std::vector<int> data);
};

#endif // PMERGEME_HPP
