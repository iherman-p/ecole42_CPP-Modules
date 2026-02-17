/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:20:36 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/17 15:24:01 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <cstddef>
# include <exception>
# include <vector>

class Span
{
	private:
		std::vector<int>			elements_;
		std::size_t					maxElements_;
		static const std::size_t	kDefaultMaxElements;
	public:
		Span();
		Span(const Span& other);
		Span(std::size_t N);
		~Span();

		Span&	operator=(const Span& other);

		void			addNumber(int n);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		std::size_t		size() const;
		std::size_t		maxSize() const;

		typedef std::vector<int>::iterator					iterator;
		typedef std::vector<int>::const_iterator			const_iterator;
		typedef std::vector<int>::reverse_iterator			reverse_iterator;
		typedef std::vector<int>::const_reverse_iterator	const_reverse_iterator;

		iterator	begin();
		iterator	end();

		const_iterator	begin() const;
		const_iterator	end() const;

		reverse_iterator	rbegin();
		reverse_iterator	rend();

		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;

		class MaxElementsReached : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InsufficientElements : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif // SPAN_HPP
