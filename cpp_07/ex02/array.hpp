/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:32:26 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/15 16:00:28 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
	private:
		T		*_array;
		size_t	_size;
	public:
		Array();
		Array(size_t n);
		Array(const Array& other);
		~Array();
		Array&		operator=(const Array& other);

		T&			operator[] (size_t i);
		const T&	operator[] (size_t i) const;

		size_t		size(void) const;

		class OutOfBoundAccess : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "array.tpp"

#endif // ARRAY_HPP