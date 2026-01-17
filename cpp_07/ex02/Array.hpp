/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:32:26 by iherman-          #+#    #+#             */
/*   Updated: 2026/01/17 19:28:00 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <cstddef>
#include <ostream>

template <typename T>
class Array
{
	private:
		T		*array_;
		size_t	size_;
	public:
		Array();
		Array(size_t n);
		Array(const Array& other);
		~Array();
		Array&		operator=(const Array& other);

		T&			operator[] (size_t i);
		const T&	operator[] (size_t i) const;

		size_t		size() const;

		class OutOfBoundsAccess : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif // ARRAY_HPP