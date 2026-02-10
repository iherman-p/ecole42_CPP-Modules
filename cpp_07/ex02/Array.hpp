/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:32:26 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/10 18:13:48 by iherman-         ###   ########.fr       */
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
		T			*array_;
		std::size_t	size_;
	public:
		Array();
		Array(std::size_t n);
		Array(const Array& other);
		~Array();
		Array&		operator=(const Array& other);

		T&			operator[] (std::size_t i);
		const T&	operator[] (std::size_t i) const;

		std::size_t		size() const;

		class OutOfBoundsAccess : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& arr);

#include "Array.tpp"

#endif // ARRAY_HPP