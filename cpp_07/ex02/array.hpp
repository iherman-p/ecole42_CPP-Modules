/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:32:26 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/14 18:52:12 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>

template <typename T> class Array
{
	private:
		T		*_array;
		size_t	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(T& other);
		~Array();

		int&	operator[] (int i);

		int		size(void);

		class OutOfBoundAccess : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "array.tpp"

#endif // ARRAY_HPP