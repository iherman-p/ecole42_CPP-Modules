/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:45:07 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/17 15:25:04 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

const std::size_t	Span::kDefaultMaxElements = 8;

Span::Span()
	: elements_(),
		maxElements_(kDefaultMaxElements)
{
}

Span::Span(const Span& other)
	: elements_(other.elements_),
		maxElements_(other.maxElements_)
{
	
}

Span::Span(std::size_t n)
	: elements_(),
		maxElements_(n)
{
	elements_.reserve(n);
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxElements_ = other.maxElements_;
		elements_ = other.elements_;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (elements_.size() == maxElements_)
		throw MaxElementsReached();
	elements_.push_back(n);
}

unsigned int	Span::shortestSpan() const
{
	if (elements_.size() <= 1)
	{
		throw InsufficientElements();
	}

	unsigned int		min_span;
	std::vector<int>	sorted(elements_);

	std::sort(sorted.begin(), sorted.end());
	min_span = sorted[1] - sorted[0];
	for (std::size_t i = 2; i < sorted.size(); ++i)
	{
		long diff = static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]);
		min_span = std::min(min_span, static_cast<unsigned int>(diff));
	}
	return min_span;
}

unsigned int	Span::longestSpan() const
{
	int	largest;
	int	smallest;

	if (elements_.size() <= 1)
	{
		throw InsufficientElements();
	}

	largest = elements_[0];
	smallest = elements_[0];
	for (std::size_t i = 1; i < elements_.size(); ++i)
	{
		largest = std::max(largest, elements_[i]);
		smallest = std::min(smallest, elements_[i]);
	}
	long diff = static_cast<long>(largest) - static_cast<long>(smallest);
	return static_cast<unsigned int>(diff);
}

std::size_t	Span::size() const
{
	return elements_.size();
}

std::size_t	Span::maxSize() const
{
	return maxElements_;
}

Span::iterator Span::begin()
{
	return elements_.begin();
}

Span::iterator Span::end()
{
	return elements_.end();
}

Span::const_iterator Span::begin() const
{
	return elements_.begin();
}

Span::const_iterator Span::end() const
{
	return elements_.end();
}

Span::reverse_iterator Span::rbegin()
{
	return elements_.rbegin();
}

Span::reverse_iterator Span::rend()
{
	return elements_.rend();
}

Span::const_reverse_iterator Span::rbegin() const
{
	return elements_.rbegin();
}

Span::const_reverse_iterator Span::rend() const
{
	return elements_.rend();
}


const char* Span::MaxElementsReached::what() const throw()
{
	return "Too many elements";
}

const char* Span::InsufficientElements::what() const throw()
{
	return "Insufficient elements";
}
